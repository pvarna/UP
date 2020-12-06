#include <iostream>

// checks if a given year is leap or not
bool isYearLeap (int year);

// checks if a given date (day, month, year) is valid 
bool isDateValid (int day, int month, int year);

int sumOfDigits (int number);

int main ()
{
    int day, month, year;

    std::cin >> day >> month >> year;

    if(!isDateValid(day, month, year))
    {
        std::cout << "Invalid date!" << std::endl;
    }
    else
    {
        if ((sumOfDigits(day) + sumOfDigits(month) + sumOfDigits(year)) % 6 == 0)
        {
            std::cout << "Lucky" << std::endl;
        }
        else
        {
            std::cout << "Not Lucky" << std::endl;
        }
        
    }
    

    return 0;
}

bool isYearLeap (int year)
{
    if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
    {
        return true;
    }
    return false;
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

int sumOfDigits (int number)
{
    int temp = number, sum = 0;
    while (temp)
    {
        sum += (temp % 10);
        temp /= 10;
    }
    return sum;
}