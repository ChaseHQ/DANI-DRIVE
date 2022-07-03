#include "rtc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"

void SetClock(size_t year, uint8_t month, uint8_t dayOfMonth, uint8_t dayOfWeek, uint8_t hour, uint8_t minute, uint8_t second) {
    year -= 2000;
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
    min = I2C1_Read1ByteRegister(CLOCK_ADDR,0x01);
    hour = I2C1_Read1ByteRegister(CLOCK_ADDR,0x02);
    weekday = I2C1_Read1ByteRegister(CLOCK_ADDR,0x03);
    day = I2C1_Read1ByteRegister(CLOCK_ADDR,0x04);
    month = I2C1_Read1ByteRegister(CLOCK_ADDR,0x05);
    year = I2C1_Read1ByteRegister(CLOCK_ADDR,0x06);
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

