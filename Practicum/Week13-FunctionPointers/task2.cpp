#include <iostream>

bool isYearLeap (int year);

enum ExitCodes
{
    OK,
    INVALID_MONTH,
    INVALID_DAY,
    INVALID_HOUR,
    INVALID_MINUTES,
    INVALID_SECONDS
};

int main ()
{
    int year, month, day, hour, minute, second;

    std::cin >> year >> month >> day >> hour >> minute >> second;
    
    // month
    if (month < 1 || month > 12)
    {
        return INVALID_MONTH;
    }

    // day
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day < 0 || day > 31)
        {
            return INVALID_DAY;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day < 0 || day > 30)
        {
            return INVALID_DAY;
        }
    }
    else if (month == 2 && isYearLeap(year))
    {
        if (day < 0 || day > 29)
        {
            return INVALID_DAY;
        }
    }
    else if (month == 2 && !isYearLeap(year))
    {
        if (day < 0 || day > 28)
        {
            return INVALID_DAY;
        }
    }

    // hour
    if (hour < 0 || hour > 23)
    {
        return INVALID_HOUR;
    }

    // minute
    if (minute < 0 || minute > 59)
    {
        return INVALID_MINUTES;
    }

    // second
    if (second < 0 || second > 59)
    {
        return INVALID_SECONDS;
    }

    return OK;
}

bool isYearLeap (int year)
{
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}