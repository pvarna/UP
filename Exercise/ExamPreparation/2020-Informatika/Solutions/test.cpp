#include <iostream>

const double EPS = 0.001;

size_t myStrLen(const char* str)
{
    size_t size = 0;

    while(*str)
    {
        ++size;
        ++str;
    }

    return size;
}

void myStrCpy(const char* what, char* where)
{
    size_t size = myStrLen(what);
    
    for (size_t i = 0; i < size; ++i)
    {
        where[i] = what[i];
    }
    where[size] = '\0';
}

int myStrCmp(const char* str1, const char* str2)
{
    while(*str1 && *str2 && *str1 == *str2)
    {
        ++str1;
        ++str2;
    }

    return *str1 - *str2;
}

double myFabs(double x)
{
    return (x >= 0) ? x : -x;
}

double mySqrt(double x)
{
    for (double i = 0; i <= x; i += 0.0000001)
    {
        if (myFabs(i*i - x) < EPS)
        {
            return i;
        }
    }
    return -1;
}

int main ()
{
    double n;

    std::cin >> n;

    std::cout << mySqrt(n) << std::endl;

    return 0;
}