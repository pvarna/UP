#include <iostream>

int getDigitCount (const char* str, int counter);

int getDigitCountWrapper (const char* str);

int main ()
{
    const char* str = "032893asdas4983dsfdsf74"; 

    std::cout << getDigitCountWrapper(str) << std::endl;

    return 0;
}

int getDigitCount (const char* str, int counter)
{
    if (!str[0])
    {
        return counter;
    }
    if (str[0] >= '0' && str[0] <= '9')
    {
        ++counter;
    }
    return getDigitCount(str+1, counter);
}

int getDigitCountWrapper (const char* str)
{
    return getDigitCount(str, 0);
}