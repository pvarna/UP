#include <iostream>

int main ()
{
    for (int i = 1000; i < 10000; ++i)
    {
        int ones = i % 10;
        int tens = i / 10 % 10;
        int hundreds = i / 100 % 10;
        int thousands = i / 1000;

        if ((ones + tens) == (hundreds + thousands))
        {
            std::cout << i << std::endl;
        }
    }
    return 0;
}