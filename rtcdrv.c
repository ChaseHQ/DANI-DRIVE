#include "rtcdrv.h"
#include <string.h>

#define ACK_Recv() delay(500);CA1_SetLow();delay(500);CA1_SetHigh();

#define RTC_CMD_GETACLK 0b0000
#define RTC_CMD_GETCLK  0b0001
#define RTC_SET_CLK     0b1000

#define DRV_DIR         0b0000
#define DRV_LOAD        0b1000

#define SET_OUT() TRISA = 0x00
#define SET_IN() TRISA = 0xFF

FATFS drive;
FIL file;
FFDIR dir;
FILINFO fno;
FATFS *fs;

void sendBuffer(char * buff, unsigned int size) {
    SET_OUT();
    int i = 0;
    while (i < size) {
        PORTA = buff[i++];
        ACK_Recv(); // Let DANI know we have data and wait
        while (CA2_GetValue()); // Wait for it to tell us it took it
    }
    ACK_Recv(); // Generate one more ACK that data is done
}

void sendBufferLen(size_t bufferLen) {
    char outbuff[2] = {bufferLen, bufferLen >> 8};
    sendBuffer(outbuff, 2); // Send Byte Size
}

void sendFile(FIL * file) {
    BYTE byte = 0;
    BYTE bread = 0;
    SET_OUT();
    do {
        f_read(file,&byte,1,&bread);
        PORTA = byte;
        ACK_Recv();
        while (bread && CA2_GetValue());
    } while(bread);
    ACK_Recv(); // Generate one more ACK that data is done
}

void getBuffer(size_t bufferSize, BYTE * buffer) {
    SET_IN();
    int i = 0;
    while (i < bufferSize) {
        while (CA2_GetValue()); // Wait until it tells us there is data waiting
        buffer[i++] = PORTA;
        ACK_Recv(); // Let Them know we took the data
    }
}

void getArgs(size_t argsCount, BYTE * buffer) {
    return getBuffer(argsCount, buffer);
}

void rtcGetAClk() {
    struct tm t = ReadClock();
    char * bufferOut = asctime(&t);
    size_t outSize = strlen(bufferOut)+1;
    bufferOut[(--outSize)-1] = 0; // Null Terminate the '\n'
    sendBufferLen(outSize);
    sendBuffer(bufferOut, outSize);
}

void rtcGetClk() {
    struct tm t = ReadClock();
    BYTE bufferOut[8] = {(t.tm_year+1900)/100, (t.tm_year+1900) - (((t.tm_year+1900) / 1000) * 1000), t.tm_mon+1, t.tm_mday, t.tm_wday+1, t.tm_hour, t.tm_min, t.tm_sec};
    sendBufferLen(8);
    sendBuffer(bufferOut,8);
}

void rtcSetClk(BYTE argCount) {
    BYTE * argBuffer = (BYTE *)malloc(argCount);
    getArgs(argCount,argBuffer);
    BYTE * buffer = (BYTE *)malloc(argBuffer[0]);
    getBuffer(argBuffer[0],buffer);
    size_t year = (buffer[0]*100)+buffer[1];
    SetClock(year,buffer[2],buffer[3],buffer[4],buffer[5],buffer[6],buffer[7]);
    free(argBuffer);
    free(buffer);
}

void processRTC(BYTE cmd, BYTE argCount) {
    switch(cmd) {
        case RTC_CMD_GETACLK:
            rtcGetAClk();
            break;
        case RTC_CMD_GETCLK:
            rtcGetClk();
            break;
        case RTC_SET_CLK:
            rtcSetClk(argCount);
            break;
    }
}

void drvGetDir() {
    if (DRVA_IsMediaPresent() && (f_mount(&drive,"0:",1) == FR_OK)) {
        
        char buffer[256] = {};
        char driveLabel[34] = {};
        size_t fileCount = 0;
        DWORD fre_clust, fre_sect, tot_sect;
        
        f_opendir(&dir, "");
        do {
            f_readdir(&dir, &fno);
            if (!fno.fname[0]) continue; // Skip this file it's blank
            if (!fno.fsize) continue;    // Skip zero file sized files
            fileCount++;
        } while (fno.fname[0]);
        f_rewinddir(&dir);
        // File count now contains the count of the files in the directory
        sendBufferLen(fileCount+6); // We will send the amount of files + 6, header + free + additional CRs
        sendBuffer("",1);
        f_getlabel("",driveLabel,0);
        sprintf(buffer,"*Volume - %s*", driveLabel);
        sendBuffer(buffer,strlen(buffer)+1);
        sendBuffer("",1);
        do {
            f_readdir(&dir, &fno);
            if (!fno.fname[0]) continue; // Skip this file it's blank
            if (!fno.fsize) continue;    // Skip zero file sized files
            memset(buffer,0,256);
            sprintf(buffer,"%12s - %lu bytes",fno.fname,fno.fsize);
            sendBuffer(buffer,strlen(buffer)+1);
        } while (fno.fname[0]);
        sendBuffer("",1);
        memset(buffer,0,256);
        f_getfree("", &fre_clust, &fs);
        tot_sect = (fs->n_fatent - 2) * fs->csize;
        fre_sect = fre_clust * fs->csize;
        sprintf(buffer, "%lu KiB free",fre_sect / 2);
        sendBuffer(buffer,strlen(buffer)+1);
        sendBuffer("",1);
        
        f_mount(0,"0:",0);
    } else {
        sendBufferLen(0);
    }
}

void drvLoad(BYTE argCount) {
    BYTE * argBuffer = (BYTE *)malloc(argCount);
    getArgs(argCount,argBuffer);
    BYTE * buffer = (BYTE *)malloc(argBuffer[0]);
    getBuffer(argBuffer[0],buffer);
    
    if (DRVA_IsMediaPresent() && (f_mount(&drive,"0:",1) == FR_OK)) {
        
        if (f_open(&file,buffer,FA_READ|FA_OPEN_EXISTING) == FR_OK) {
            sendBufferLen(f_size(&file));
            sendFile(&file);
            f_close(&file);
        } else {
            sendBufferLen(0);
        }
        f_mount(0,"0:",0);
    } else {
        sendBufferLen(0);
    }
    
    free(argBuffer);
    free(buffer);
}

void processDRV(BYTE cmd, BYTE argCount) {
    switch (cmd) {
        case DRV_DIR:
            drvGetDir();
            break;
        case DRV_LOAD:
            drvLoad(argCount);
            break;
    }
}

void rtcdrv_poll(void) {
    if (!CA2_GetValue()) {
        // We have Data Waiting
        RTCDRV_DATA d;
        d.data = PORTA;
        ACK_Recv(); // Ack that the command was recieved & Process it
        // Process the command
        if (d.data_part.rtc) {
            // it's a real time clock command
            processRTC(d.data_part.cmd, d.data_part.argCount);
        } else {
            // It's a Drive Command
            processDRV(d.data_part.cmd, d.data_part.argCount);
        }
        SET_IN(); // Set Direction back inward and wait for next CMD
    } 
}
