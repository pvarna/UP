#include <iostream>

int main ()
{
    for (int i = 100; i < 1000; ++i)
    {
        int ones = i % 10;
        int tens = i / 10 % 10;
        int hundreds = i / 100;

        if ((ones != tens) && (tens != hundreds) && (ones != hundreds))
        {
            std::cout << i << std::endl;
        }
    }

    return 0;
}