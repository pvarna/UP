#include <iostream>
#include <cmath>

// checks if a given year is leap or not
bool isYearLeap (int year);

// checks if a given date (day, month, year) is valid 
bool isDateValid (int day, int month, int year);

// checks if a given hour (hour, minutes, seconds) is valid
bool isHourValid (int hour, int minutes, int seconds);

// counts how many '29 February' days have passed until the start of a given year (starts from year 0) 
int numberOf29FebruaryToYear (int year);

// converts a given time (year, month, day, hour, minutes, seconds) into seconds
unsigned long long int convertTimeToSeconds (int year, int month, int day, int hour, int minutes, int seconds);

int main ()
{
    int day1, day2, month1, month2, year1, year2, hour1, hour2, minutes1, minutes2, seconds1, seconds2;
    char delim1_1, delim1_2, delim1_3, delim1_4, delim2_1, delim2_2, delim2_3, delim2_4;
    bool validInput = true; // boolean variable checking the validation of the input

    std::cin >> day1 >> delim1_1 >> month1 >> delim1_2 >> year1 >> hour1 >> delim1_3 >> minutes1 >> delim1_4 >> seconds1;
    std::cin >> day2 >> delim2_1 >> month2 >> delim2_2 >> year2 >> hour2 >> delim2_3 >> minutes2 >> delim2_4 >> seconds2;
  
    // INPUT VALIDATION
    // ****************
    // checking if the delimeters '.' and ':' are in the correct positions
    if ((delim1_1 != '.') || (delim1_2 != '.') || (delim1_3 != ':') || (delim1_4 != ':') 
        || (delim2_1 != '.') || (delim2_2 != '.') || (delim2_3 != ':') || (delim2_4 != ':'))
    {
        std::cout << "Invalid date/time" << std::endl;
        validInput = false;
    }
    // checking if the dates are valid
    else if (!isDateValid(day1, month1, year1) || !isDateValid(day2, month2, year2))
    {
        std::cout << "Invalid date/time" << std::endl;
        validInput = false;   
    }
    // checking if the hours are valid
    else if (!isHourValid(hour1, minutes1, seconds1) || !isHourValid(hour2, minutes2, seconds2))
    {
        std::cout << "Invalid date/time" << std::endl;
        validInput = false;
    }

    if (validInput)
    {
        // converting the two times into seconds
        unsigned long long int time1ToSeconds = convertTimeToSeconds(year1, month1, day1, hour1, minutes1, seconds1);
        unsigned long long int time2ToSeconds = convertTimeToSeconds(year2, month2, day2, hour2, minutes2, seconds2);
        unsigned long long int timeDifferenceInSeconds;

        // calculating the absolute difference
        if (time1ToSeconds > time2ToSeconds)
        {
            timeDifferenceInSeconds = time1ToSeconds - time2ToSeconds;
        }
        else
        {
            timeDifferenceInSeconds = time2ToSeconds - time1ToSeconds;
        }
        
        int daysDifference = timeDifferenceInSeconds / (24 * 60 * 60); // converting the difference in seconds into days
        int remainingSeconds = timeDifferenceInSeconds % (24 * 60 * 60); // remainder
        int hourDifference = remainingSeconds / 3600; // converting the remaining seconds into hours
        remainingSeconds = remainingSeconds % 3600; // remainder
        int minutesDifference = remainingSeconds / 60; // converting the remaining seconds into minutes
        remainingSeconds = remainingSeconds % 60; // remainder
        int secondsDifference = remainingSeconds; // remaining seconds

        // printing the day difference if there is any
        if (daysDifference > 0)
        {
            std::cout << daysDifference << "-";
        }

        // adding '0' if the hours are one-digit
        if(hourDifference < 10)
        {
            std::cout << "0" << hourDifference << ":";
        }
        else
        {
            std::cout << hourDifference << ":";
        }

        // adding '0' if the minutes are one-digit
        if(minutesDifference < 10)
        {
            std::cout << "0" << minutesDifference << ":";
        }
        else
        {
            std::cout << minutesDifference << ":";
        }
        
        // adding '0' if the seconds are one-digit
        if(secondsDifference < 10)
        {
            std::cout << "0" << secondsDifference;
        }
        else
        {
            std::cout << secondsDifference;
        }
    }

    return 0;
}

bool isYearLeap (int year)
{
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

bool isDateValid (int day, int month, int year)
{
    if (year < 0 || year > 9999)
    {
        return false;
    }
    if (month < 1 || month > 12)
    {
        return false;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day < 0 || day > 31)
        {
            return false;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day < 0 || day > 30)
        {
            return false;
        }
    }
    else if (month == 2 && isYearLeap(year))
    {
        if (day < 0 || day > 29)
        {
            return false;
        }
    }
    else if (month == 2 && !isYearLeap(year))
    {
        if (day < 0 || day > 28)
        {
            return false;
        }
    }
    return true; // if all checks are successful, the given date is valid
}

bool isHourValid (int hour, int minutes, int seconds)
{
    if (hour < 0 || hour > 23)
    {
        return false;
    }
    if (minutes < 0 || minutes > 59)
    {
        return false;
    }
    if (seconds < 0 || seconds > 59)
    {
        return false;
    }
    return true; // if all checks are successful, the given hour is valid
}

int numberOf29FebruaryToYear (int year)
{
    if (year == 0) // there are no '29 February' days before year 0
    {
        return 0;
    }
    --year; // reducing the years by 1 because we count the '29 February' days before the given year
    return (year / 4 - year / 100 + year / 400 + 1); // adding 1 because the year 0 also has a '29 February' day
}

unsigned long long int convertTimeToSeconds (int year, int month, int day, int hour, int minutes, int seconds)
{
    unsigned long long int yearToDays;

    yearToDays = year * 365 + numberOf29FebruaryToYear(year); // number of days in the years before the given year
    // we multiply 365 by ((year-1) previous year [1:(year-1)] + the year 0) (year - 1 + 1 = year) 
    // and then add the number of '29 February' days that have passed until the start of the given year 

    // adding the number of days from the given year depending on the given month
    if (month == 1)
    {
        yearToDays += day;
    }
    else if (month == 2)
    {
        yearToDays += (31 + day);
    }
    else if (month == 3)
    {
        yearToDays += (31 + 28 + day);
    }
    else if (month == 4)
    {
        yearToDays += (31 + 28 + 31 + day);
    }
    else if (month == 5)
    {
        yearToDays += (31 + 28 + 31 + 30 + day);
    }
    else if (month == 6)
    {
        yearToDays += (31 + 28 + 31 + 30 + 31 + day);
    }
    else if (month == 7)
    {
        yearToDays += (31 + 28 + 31 + 30 + 31 + 30 + day);
    }
    else if (month == 8)
    {
        yearToDays += (31 + 28 + 31 + 30 + 31 + 30 + 31 + day);
    }
    else if (month == 9)
    {
        yearToDays += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day);
    }
    else if (month == 10)
    {
        yearToDays += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day);
    }
    else if (month == 11)
    {
        yearToDays += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day);
    }
    else if (month == 12)
    {
        yearToDays += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day);
    }
    if (isYearLeap(year) && month > 2) // adding a day if the year is leap and February has passed
    {
        ++yearToDays;
    }

    unsigned long long daysToSeconds = yearToDays * 24 * 60 * 60; // converting the days into seconds

    daysToSeconds += (hour * 3600 + minutes * 60 + seconds); // adding the seconds from the given hour by converting the hours and the minutes into seconds

    return daysToSeconds;
}