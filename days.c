/*
 * Author: GN-z11Codes
 * Description: Calculate the number of days you've lived from the current date.
 */

#include <stdio.h>
#include <time.h>

/**
 * days_in_month - Get the number of days in a month, considering leap years.
 * @year: The year.
 * @month: The month (1-12).
 *
 * Return: The number of days in the specified month.
 */
int days_in_month(int year, int month)
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        days[2] = 29;

    return days[month];
}

/**
 * days_from_date - Calculate the total number of days from a given date (year, month, day).
 * @year: The year.
 * @month: The month (1-12).
 * @day: The day of the month (1-31).
 *
 * Return: The total number of days from the specified date.
 */
int days_from_date(int year, int month, int day)
{
    int total_days = 0;
    int i;

    for (i = 1; i < year; i++) {
        total_days += 365;
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
            total_days++;
    }

    for (i = 1; i < month; i++)
        total_days += days_in_month(year, i);

    total_days += day;

    return total_days;
}

int main(void)
{
    time_t t;
    struct tm *now;
    int current_year, current_month, current_day;
    int birth_year, birth_month, birth_day;

    time(&t);
    now = localtime(&t);
    current_year = now->tm_year + 1900;
    current_month = now->tm_mon + 1;
    current_day = now->tm_mday;

    printf("Enter your birthdate (YYYY MM DD): ");
    scanf("%d %d %d", &birth_year, &birth_month, &birth_day);

    int days_lived = days_from_date(current_year, current_month, current_day) - days_from_date(birth_year, birth_month, birth_day);

    printf("You have lived %d days.\n", days_lived);

    return (0);
}

