#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/fatfs/drva.h"
#include "rtcdrv.h"

/*    FATFS drive;
    FIL file;
    FFDIR dir;
    FILINFO fno;*/

/*void DiskTest() {
    UINT actualLength;
    char data[] = "Hello World!";

    if (DRVA_IsMediaPresent()) {
        // Disk is here
        if (f_mount(&drive,"0:",1) == FR_OK)
        {
            if (f_open(&file, "another.txt", FA_WRITE | FA_CREATE_NEW ) == FR_OK)
            {
                f_write(&file, data, sizeof(data)-1, &actualLength );
                f_close(&file);
            }
            /*f_opendir(&dir,"");
            do {
                f_readdir(&dir, &fno);
            } while (fno.fname[0]);
            
            f_mount(0,"0:",0);
        }
        NOP();
    }
}*/

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
    
    //DiskTest();
    
    while(1) {
        rtcdrv_poll();
    }
}

