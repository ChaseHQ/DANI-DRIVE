#include "mcc_generated_files/mcc.h"
#include "rtcdrv.h"

void main(void)
{
#ifdef __DEBUG
    delay(30000); // Delay is needed so code execution then debug reset doesn't hang SDA - 
#endif
    SYSTEM_Initialize();
    
    TMR0_SetInterruptHandler(DRVA_TMR_ms);
    IOCBF5_SetInterruptHandler(DRVA_IOCCD);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    TMR0_StartTimer();
    
    while(1) {
        rtcdrv_poll();
    }
}

