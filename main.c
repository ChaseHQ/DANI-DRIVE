#include "mcc_generated_files/mcc.h"
#include <string.h>
#include "mcc_generated_files/fatfs/ff.h"
#include "mcc_generated_files/fatfs/drva.h"
#include "rtc.h"

#define delay(wait) for (int x = 0; x < wait; ++x) NOP();

    FATFS drive;
    FIL file;
    FFDIR dir;
    FILINFO fno;

void DiskTest() {
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
            } while (fno.fname[0]);*/
            
            f_mount(0,"0:",0);
        }
        NOP();
    }
}

void CA2IOC(void) {
    delay(500);
    CA1_SetLow();
    delay(500);
    CA1_SetHigh();
}

void main(void)
{
#ifdef __DEBUG
    delay(30000); // Delay is needed so code execution then debug reset doesn't hang SDA - 
#endif
    SYSTEM_Initialize();
    
    TMR0_SetInterruptHandler(DRVA_TMR_ms);
    IOCCF1_SetInterruptHandler(CA2IOC);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    TMR0_StartTimer();
    
    //DiskTest();
    

    while (1);
}

