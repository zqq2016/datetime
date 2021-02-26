//
// Created by zhouquanqiu on 2021/1/28.
//

#include <stdio.h>
#include <string.h>
#include "datetime.h"

#define DAYS (24*3600)
#define FOURYEARS (365*3+366)
#define BASE_TIME_TICK (946656000UL)    // 北京时间2000-01-01 00:00:00

static const unsigned short days[4][12] = {
        {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335},
        {366, 397, 425, 456, 486, 517, 547, 578, 609, 639, 670, 700},
        {731, 762, 790, 821, 851, 882, 912, 943, 974, 1004, 1035, 1065},
        {1096, 1127, 1155, 1186, 1216, 1247, 1277, 1308, 1339, 1369, 1400, 1430},
};


unsigned int date_time_to_epoch(rtc_timedate_t *date_time)
{
    unsigned int second = date_time->seconds;   // 0-59
    unsigned int minute = date_time->minutes;   // 0-59
    unsigned int hour = date_time->hour;        // 0-23
    unsigned int day = date_time->day - 1;      // 0-30
    unsigned int month = date_time->month - 1;  // 0-11
    unsigned int year = date_time->year - 2000; // 0-99
    unsigned int temp = 0;
    temp = year / 4;
    temp = temp * (365 * 4 + 1);
    temp = temp + days[year%4][month];
    temp += day;
    return (((year / 4 * (365 * 4 + 1) + days[year % 4][month] + day) * 24 + hour) * 60 + minute) * 60 + second + BASE_TIME_TICK;
}
void date_time_get_calendar(unsigned int time_tick, rtc_timedate_t *date_time)
{
    unsigned int remind_days = 0;
    memset(date_time, 0, sizeof(*date_time));
    time_tick -= BASE_TIME_TICK;
    date_time->seconds = time_tick % 60;
    date_time->minutes = (time_tick / 60) % 60;
    date_time->hour = (time_tick / 3600) % 24;
    remind_days = (time_tick / 3600) / 24;

    date_time->year = 2000 + remind_days/FOURYEARS * 4;
    remind_days = remind_days%FOURYEARS;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 12; j++)
        {
            if (remind_days < days[i][j])
            {
                date_time->year += i;
                date_time->month = j;
                date_time->day = remind_days - days[i][j-1] + 1;
                return ;
            }
        }
    }
}