#include <iostream>

int main ()
{
    int k, number, sumNumbers = 0, counter = 0;

    std::cin >> k >> number;

    sumNumbers += number;
    ++counter;

    while (sumNumbers < k)
    {
        ++counter;

        std::cin >> number;

        sumNumbers += number;
    }

    std::cout << counter << std::endl;

    return 0;
}