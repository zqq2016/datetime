#include <stdio.h>
#include <time.h>
#include "datetime.h"

int main() {
    printf("Hello, World!\n");
    rtc_timedate_t date;

    date.year = 2021;
    date.month = 2;
    date.day = 28;
    date.hour = 12;
    date.minutes = 02;
    date.seconds = 00;
    printf("%u\n",date_time_to_epoch(&date));

    date_time_get_calendar(1583031150, &date);

    printf("%d-%d-%d:%d:%d:%d\n", date.year, date.month, date.day, date.hour, date.minutes, date.seconds);
//    date_time_get__calendar(time(NULL), &date);
//    printf("%d-%d-%d:%d:%d:%d\n", date.year, date.month, date.day, date.hour, date.minutes, date.seconds);
    return 0;
}
