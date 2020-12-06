#include <iostream>

int main ()
{
    int number, sum = 0, counter = 0;

    std::cin >> number;

    if (number == 0)
    {
        std::cout << 0;
    }
    else
    {
        while (number)
        {
            sum += number;
            ++counter;

            std::cin >> number;
        }

        std::cout << ((double)sum) / ((double)counter);
    }

    return 0;
}