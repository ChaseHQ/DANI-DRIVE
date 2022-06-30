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

// get/set PA0 aliases
#define PA0_TRIS                 TRISAbits.TRISA0
#define PA0_LAT                  LATAbits.LATA0
#define PA0_PORT                 PORTAbits.RA0
#define PA0_WPU                  WPUAbits.WPUA0
#define PA0_OD                   ODCONAbits.ODCA0
#define PA0_ANS                  ANSELAbits.ANSELA0
#define PA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define PA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define PA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define PA0_GetValue()           PORTAbits.RA0
#define PA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define PA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define PA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define PA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define PA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define PA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define PA0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define PA0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set PA1 aliases
#define PA1_TRIS                 TRISAbits.TRISA1
#define PA1_LAT                  LATAbits.LATA1
#define PA1_PORT                 PORTAbits.RA1
#define PA1_WPU                  WPUAbits.WPUA1
#define PA1_OD                   ODCONAbits.ODCA1
#define PA1_ANS                  ANSELAbits.ANSELA1
#define PA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define PA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define PA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define PA1_GetValue()           PORTAbits.RA1
#define PA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define PA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define PA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define PA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define PA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define PA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define PA1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define PA1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set PA2 aliases
#define PA2_TRIS                 TRISAbits.TRISA2
#define PA2_LAT                  LATAbits.LATA2
#define PA2_PORT                 PORTAbits.RA2
#define PA2_WPU                  WPUAbits.WPUA2
#define PA2_OD                   ODCONAbits.ODCA2
#define PA2_ANS                  ANSELAbits.ANSELA2
#define PA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define PA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define PA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define PA2_GetValue()           PORTAbits.RA2
#define PA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define PA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define PA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define PA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define PA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define PA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define PA2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define PA2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set PA3 aliases
#define PA3_TRIS                 TRISAbits.TRISA3
#define PA3_LAT                  LATAbits.LATA3
#define PA3_PORT                 PORTAbits.RA3
#define PA3_WPU                  WPUAbits.WPUA3
#define PA3_OD                   ODCONAbits.ODCA3
#define PA3_ANS                  ANSELAbits.ANSELA3
#define PA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define PA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define PA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define PA3_GetValue()           PORTAbits.RA3
#define PA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define PA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define PA3_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define PA3_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define PA3_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define PA3_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define PA3_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define PA3_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set PA4 aliases
#define PA4_TRIS                 TRISAbits.TRISA4
#define PA4_LAT                  LATAbits.LATA4
#define PA4_PORT                 PORTAbits.RA4
#define PA4_WPU                  WPUAbits.WPUA4
#define PA4_OD                   ODCONAbits.ODCA4
#define PA4_ANS                  ANSELAbits.ANSELA4
#define PA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define PA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define PA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define PA4_GetValue()           PORTAbits.RA4
#define PA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define PA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define PA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define PA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define PA4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define PA4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define PA4_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define PA4_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set PA5 aliases
#define PA5_TRIS                 TRISAbits.TRISA5
#define PA5_LAT                  LATAbits.LATA5
#define PA5_PORT                 PORTAbits.RA5
#define PA5_WPU                  WPUAbits.WPUA5
#define PA5_OD                   ODCONAbits.ODCA5
#define PA5_ANS                  ANSELAbits.ANSELA5
#define PA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define PA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define PA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define PA5_GetValue()           PORTAbits.RA5
#define PA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define PA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define PA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define PA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define PA5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define PA5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define PA5_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define PA5_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set PA6 aliases
#define PA6_TRIS                 TRISAbits.TRISA6
#define PA6_LAT                  LATAbits.LATA6
#define PA6_PORT                 PORTAbits.RA6
#define PA6_WPU                  WPUAbits.WPUA6
#define PA6_OD                   ODCONAbits.ODCA6
#define PA6_ANS                  ANSELAbits.ANSELA6
#define PA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define PA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define PA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define PA6_GetValue()           PORTAbits.RA6
#define PA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define PA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define PA6_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define PA6_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define PA6_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define PA6_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define PA6_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define PA6_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set PA7 aliases
#define PA7_TRIS                 TRISAbits.TRISA7
#define PA7_LAT                  LATAbits.LATA7
#define PA7_PORT                 PORTAbits.RA7
#define PA7_WPU                  WPUAbits.WPUA7
#define PA7_OD                   ODCONAbits.ODCA7
#define PA7_ANS                  ANSELAbits.ANSELA7
#define PA7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define PA7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define PA7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define PA7_GetValue()           PORTAbits.RA7
#define PA7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define PA7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define PA7_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define PA7_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define PA7_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define PA7_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define PA7_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define PA7_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

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

// get/set CA1 aliases
#define CA1_TRIS                 TRISCbits.TRISC0
#define CA1_LAT                  LATCbits.LATC0
#define CA1_PORT                 PORTCbits.RC0
#define CA1_WPU                  WPUCbits.WPUC0
#define CA1_OD                   ODCONCbits.ODCC0
#define CA1_ANS                  ANSELCbits.ANSELC0
#define CA1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define CA1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define CA1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define CA1_GetValue()           PORTCbits.RC0
#define CA1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define CA1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define CA1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define CA1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define CA1_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define CA1_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define CA1_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define CA1_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set CA2 aliases
#define CA2_TRIS                 TRISCbits.TRISC1
#define CA2_LAT                  LATCbits.LATC1
#define CA2_PORT                 PORTCbits.RC1
#define CA2_WPU                  WPUCbits.WPUC1
#define CA2_OD                   ODCONCbits.ODCC1
#define CA2_ANS                  ANSELCbits.ANSELC1
#define CA2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define CA2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define CA2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define CA2_GetValue()           PORTCbits.RC1
#define CA2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define CA2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define CA2_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define CA2_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define CA2_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define CA2_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define CA2_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define CA2_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

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


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF1 pin functionality
 * @Example
    IOCCF1_ISR();
 */
void IOCCF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_InterruptHandler);

*/
extern void (*IOCCF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_DefaultInterruptHandler);

*/
void IOCCF1_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/