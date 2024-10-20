#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int i, leap;
    if(month <= 0 || day <= 0) {
        return -1;
    }

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if(month > 12 || day > daytab[leap][month]) {
        return -1;
    }

    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    if(yearday <= 0) {
        printf("INVALID YEARDAY\n");
        return;
    }

    leap = year %  4 == 0 && year % 100 != 0 || year % 400 == 0;
    if(leap && yearday > 366 || !leap && yearday > 365) {
        printf("INVALID YEARDAY\n");
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}

int main() {
    // COOOOOOLLL
    printf("%d\n", day_of_year(2024, 9, 30));
    int month = 0;
    int day = 0;

    month_day(2024, 274, &month, &day);
    printf("MONTH: %d\nDAY:%d\n", month, day);

    return 0;
}
