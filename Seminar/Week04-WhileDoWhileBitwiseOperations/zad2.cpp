#include <iostream>

int main ()
{
    int number, p = 1;

    std::cin >> number;

    if (number == 0)
    {
        std::cout << 0;
    }
    else
    {
        while (number)
        {
            p *= number;

            std::cin >> number;
        }

        std::cout << p;
    }

    return 0;
}