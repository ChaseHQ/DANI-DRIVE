#ifndef RTC_H
#define	RTC_H

#include "mcc_generated_files/mcc.h"
#include <time.h>
#define CLOCK_ADDR 0b1101000

void SetClock(uint8_t year, uint8_t month, uint8_t dayOfMonth, uint8_t dayOfWeek, uint8_t hour, uint8_t minute, uint8_t second);
struct tm ReadClock();

#endif	/* RTC_H */

