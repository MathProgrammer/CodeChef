#include <stdio.h>

void print_day(int day)
{
    switch(day)
    {
        case 0: printf("monday\n");
                return;

        case 1: printf("tuesday\n");
                return;

        case 2: printf("wednesday\n");
                return;

        case 3: printf("thursday\n");
                return;

        case 4: printf("friday\n");
                return;

        case 5: printf("saturday\n");
                return;

        case 6: printf("sunday\n");
                return;
    }
}

int is_leap_year(int year)
{
    if(year%400 == 0)
        return true;
    else if(year%4 == 0 && year%100 != 0)
        return true;
    else
        return false;
}

void solve()
{
    int year, offset = 0;
    scanf("%d", &year);

    if(year <= 2001)
    {
        for(int year_i = year; year_i < 2001; year_i++)//Stop before 2001 because February 2001 doesn't it's January
        {
            //We go backwards so we check if the current year is a leap year, then Monday goes 2 days back ... Leap year impacts January 1st.
            offset += (is_leap_year(year_i) ? 2 : 1);
        }
        offset = (offset%7 == 0 ? 0 : 7 - offset%7); // We're going backwards
    }
    else
    {
        for(int year_i = 2001; year_i < year; year_i++)
        {
            //We go front so we check if previous year is a leap year, since current year leap year doesn't impact January 1
            offset += (is_leap_year(year_i) ? 2 : 1);
        }
    }

    print_day(offset%7);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
