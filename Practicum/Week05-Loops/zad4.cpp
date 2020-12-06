#include <iostream>

int main ()
{
    int number, sum = 0;

    std::cin >> number;

    while(number)
    {
        sum += number;

        std::cin >> number;
    }

    std::cout << sum << std::endl;

    return 0;
}