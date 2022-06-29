/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F27K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set SCS2 aliases
#define SCS2_TRIS                 TRISBbits.TRISB4
#define SCS2_LAT                  LATBbits.LATB4
#define SCS2_PORT                 PORTBbits.RB4
#define SCS2_WPU                  WPUBbits.WPUB4
#define SCS2_OD                   ODCONBbits.ODCB4
#define SCS2_ANS                  ANSELBbits.ANSELB4
#define SCS2_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SCS2_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SCS2_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SCS2_GetValue()           PORTBbits.RB4
#define SCS2_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SCS2_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SCS2_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SCS2_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SCS2_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SCS2_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SCS2_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define SCS2_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set SDCD aliases
#define SDCD_TRIS                 TRISBbits.TRISB5
#define SDCD_LAT                  LATBbits.LATB5
#define SDCD_PORT                 PORTBbits.RB5
#define SDCD_WPU                  WPUBbits.WPUB5
#define SDCD_OD                   ODCONBbits.ODCB5
#define SDCD_ANS                  ANSELBbits.ANSELB5
#define SDCD_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define SDCD_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define SDCD_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define SDCD_GetValue()           PORTBbits.RB5
#define SDCD_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define SDCD_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define SDCD_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define SDCD_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define SDCD_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define SDCD_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define SDCD_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define SDCD_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/