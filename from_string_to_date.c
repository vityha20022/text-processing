#include <time.h>
#include "from_string_to_date.h"
#include <stdio.h>
#include <string.h>

time_t from_string_to_date(char *str)
{
    int year, mon, day;
    int len = strlen(str) - 1;
    if ((sscanf(str, "%d/%d/%d", &day, &mon, &year) == 3 && len == 9) || (len == 10 && (str[len] == '.' || str[len] == ',') && sscanf(str, "%d/%d/%d", &day, &mon, &year) == 3))
    {
        struct tm time;
        memset(&time, 0, sizeof(time)); // Обнуляем структуру
        time.tm_mon = mon - 1;
        time.tm_mday = day;
        time.tm_year = year - 1900;
        time.tm_isdst = -1;

        return mktime(&time);
    }
    return -1;
}
