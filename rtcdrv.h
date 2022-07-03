#ifndef RTCDRV_H
#define	RTCDRV_H

#define delay(wait) for (int x = 0; x < wait; ++x) NOP();

#include "mcc_generated_files/mcc.h"
#include "rtc.h"
#include "mcc_generated_files/fatfs/drva.h"

typedef union RTCDRV_DATA_ {
    struct {
        BYTE argCount : 3;
        BYTE cmd      : 4;
        BYTE rtc      : 1;
    } data_part;
    BYTE data;
} RTCDRV_DATA;

void rtcdrv_poll(void);

#endif	/* RTCDRV_H */

