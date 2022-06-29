#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
#include <time.h>
#include <string.h>
#include "mcc_generated_files/fatfs/ff.h"
#include "mcc_generated_files/fatfs/drva.h"

#define CLOCK_ADDR 0b1101000

#define delay(wait) for (int x = 0; x < wait; ++x) NOP();

static FATFS drive;
static FIL file;

void SetClock(uint8_t year, uint8_t month, uint8_t dayOfMonth, uint8_t dayOfWeek, uint8_t hour, uint8_t minute, uint8_t second) {
    uint8_t secTPlace = (second / 10);
    uint8_t secOPlace = second - (secTPlace * 10);
    uint8_t minTPlace = (minute / 10);
    uint8_t minOPlace = minute - (minTPlace * 10);
    uint8_t hourTPlace = (hour / 10);
    uint8_t hourOPlace = hour - (hourTPlace * 10);
    uint8_t dayOMTPlace = (dayOfMonth / 10);
    uint8_t dayOMOPlace = dayOfMonth - (dayOMTPlace * 10);
    uint8_t monthTPlace = (month / 10);
    uint8_t monthOPlace = month - (monthTPlace * 10);
    uint8_t yearTPlace = (year / 10);
    uint8_t yearOPlace = year - (yearTPlace * 10);
    // Apply Bit shifts
    uint8_t secToWrite = (secTPlace << 4) | secOPlace;
    uint8_t minToWrite = (minTPlace << 4) | minOPlace;
    uint8_t hourToWrite = (hourTPlace << 4) | hourOPlace;
    uint8_t dayOfMonthToWrite = (dayOMTPlace << 4) | dayOMOPlace;
    uint8_t monthToWrite = (monthTPlace << 4) | monthOPlace;
    uint8_t yearToWrite = (yearTPlace << 4) | yearOPlace;
    I2C1_Write1ByteRegister(CLOCK_ADDR,0x00, secToWrite);
    I2C1_Write1ByteRegister(CLOCK_ADDR,0x01, minToWrite);
    I2C1_Write1ByteRegister(CLOCK_ADDR,0x02, hourToWrite);
    I2C1_Write1ByteRegister(CLOCK_ADDR,0x03, dayOfWeek);
    I2C1_Write1ByteRegister(CLOCK_ADDR,0x04, dayOfMonthToWrite);
    I2C1_Write1ByteRegister(CLOCK_ADDR,0x05, monthToWrite);
    I2C1_Write1ByteRegister(CLOCK_ADDR,0x06, yearToWrite);
}

struct tm ReadClock() {
    uint8_t sec, min, hour, weekday, day, month, year;
    sec = I2C1_Read1ByteRegister(CLOCK_ADDR,0x00);
    //delay(5000);
    min = I2C1_Read1ByteRegister(CLOCK_ADDR,0x01);
    //delay(5000);
    hour = I2C1_Read1ByteRegister(CLOCK_ADDR,0x02);
    //delay(5000);
    weekday = I2C1_Read1ByteRegister(CLOCK_ADDR,0x03);
    //delay(5000);
    day = I2C1_Read1ByteRegister(CLOCK_ADDR,0x04);
    //delay(5000);
    month = I2C1_Read1ByteRegister(CLOCK_ADDR,0x05);
    //delay(5000);
    year = I2C1_Read1ByteRegister(CLOCK_ADDR,0x06);
    //delay(5000);
    struct tm t;
    t.tm_sec = ((sec & 0x70) >> 4)*10 + (sec & 0x0F);
    t.tm_min = ((min & 0x70) >> 4)*10 + (min & 0x0F);
    t.tm_hour = ((hour  & 0x30) >> 4)*10 + (hour & 0x0F);
    t.tm_wday = (weekday & 0x07) - 1;
    t.tm_mday = ((day  & 0x30) >> 4)*10 + (day  & 0x0F);
    t.tm_mon = (((month   & 0x70) >> 4)*10 + (month   & 0x0F)) - 1;
    t.tm_year = (((year & 0xF0) >> 4)*10 + (year & 0x0F)) + 100;
    return t;
}

void DiskTest() {
    UINT actualLength;
    char data[] = "Hello World!";
    
    FFDIR dir;
    FILINFO fno;
    
    if (DRVA_IsMediaPresent()) {
        // Disk is here
        if (f_mount(&drive,"0:",1) == FR_OK)
        {
            /*if (f_open(&file, "HELLO.TXT", FA_WRITE | FA_CREATE_NEW ) == FR_OK)
            {
                f_write(&file, data, sizeof(data)-1, &actualLength );
                f_close(&file);
            }*/
            f_opendir(&dir,"");
            do {
                f_readdir(&dir, &fno);
            } while (fno.fname[0]);
            
            f_mount(0,"0:",0);
        }
        NOP();
    }
}

void main(void)
{
#ifdef __DEBUG
    delay(30000); // Delay is needed so code execution then debug reset doesn't hang SDA - 
#endif
    
    SYSTEM_Initialize();
    
    TMR0_SetInterruptHandler(DRVA_TMR_ms);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    TMR0_StartTimer();
    
    //char * buffer;
    //char buffer2[254];

    //struct tm t = ReadClock();
    //buffer = asctime(&t);
    //strcpy(buffer2, buffer);
    //printf("%s",buffer2);
    
    DiskTest();
    
    while (1);
}

