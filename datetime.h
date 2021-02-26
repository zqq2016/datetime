//
// Created by zhouquanqiu on 2021/1/28.
//

#ifndef DATETIME_DATETIME_H
#define DATETIME_DATETIME_H

#include <stdint.h>

typedef struct
{
    uint16_t year;      /*!< Year       */
    uint16_t month;     /*!< Month      */
    uint16_t day;       /*!< Day        */
    uint16_t hour;      /*!< Hour       */
    uint16_t minutes;   /*!< Minutes    */
    uint8_t seconds;    /*!< Seconds    */
} rtc_timedate_t;

unsigned int date_time_to_epoch(rtc_timedate_t *date_time);
void date_time_get_calendar(unsigned int time_tick, rtc_timedate_t *date_time);

#endif //DATETIME_DATETIME_H
