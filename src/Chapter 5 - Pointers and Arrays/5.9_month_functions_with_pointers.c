#include <stdio.h>
// These are non-character digits Keep that in mind
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static const char *days[] = {daytab[0], daytab[1]};

/*
   static const char *months[] = {"0", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   // static const char *months[] = {"Illegal month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    const char* month_name(int n) {
    // could have done better like
    // return (n < 0 && n > 12) ? months[0] : months[n]
        return (n > 0 && n < 13) ? months[n] : "Invalid month";
    }
*/

// is this even right??
// the only thing i did was create an array of char pointers(just two in my case here)  to a multi-dimensional array
// this isn't any different from the other file right??

int day_of_year(int year, int month, int day) {
    int leap;
    leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)? 1 : 0;

    for(int i = 1; i < month; ++i) { 
        day += days[leap][i];
    }
    return day;
}

void month_day(int year, int yearday, int *pday, int *pmonth) {
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)? 1 : 0;

    for(i = 1; yearday > days[leap][i]; ++i) {
        yearday -= days[leap][i];
    }

    *pday = yearday;
    *pmonth = i;
}

int main() {
    // my puny idiotic brain can't handle the simplicity and genius of C
    printf("%d\n", day_of_year(2024, 10, 12));

    int day, month;
    day = month = 0;
    
    month_day(2024, 286, &day, &month);
    printf("%d\n%d\n", day, month);

    return 0;
}
