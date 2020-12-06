#include <iostream>

int main ()
{
    int number, counter = 0;

    std::cin >> number;

    while (number >= 0)
    {
        if ((number % 2 == 0) && (number != 0))
        {
            ++counter;
        }

        std::cin >> number;
    }

    std::cout << counter << std::endl;

    return 0;
}