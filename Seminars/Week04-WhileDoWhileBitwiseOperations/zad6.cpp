#include <iostream>

int main ()
{
    int number, decimalNumber = 0, base = 1;

    std::cin >> number;

    int temp = number;

    while(temp)
    {
        int lastDigit = temp % 10;

        decimalNumber += base * lastDigit;

        base *= 2;
        temp /= 10;
    }

    std::cout << decimalNumber << std::endl;

    return 0;
}