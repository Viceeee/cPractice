#include <stdio.h>
#include <stdlib.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    int nday = day_of_year(2016, 7, 15);
    int month, day;
    month_day(2016, 10, &month, &day);
    printf("%d  %d  %d", nday, month, day);
    return 0;
}

int day_of_year(int year, int month, int day){
    int leap;
    char *p;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap];
    if(month < 1 || month > 12)
        return -1;
    if(day < 1 || day > daytab[leap][month])
        return -1;
    while(--month)
        day += *++p;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
    int leap;
    char *p;
    if(year < 1){
        *pmonth = -1;
        *pday = -1;
        return;
    }
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    p = daytab[leap];
    while(yearday > *++p)
        yearday -= *p;
    if(p - *(daytab + leap) > 12 || yearday <= 0){
        *pmonth = -1;
        *pday = -1;
    } else{
        *pmonth = p - *(daytab + leap);
        *pday = yearday;
    }
}
