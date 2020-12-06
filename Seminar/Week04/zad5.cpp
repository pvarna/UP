#include <iostream>
#include <cmath>

int main ()
{
    double number, binaryNumber = 0, exponent = 0;

    std::cin >> number;

    int temp = number;

    while (temp)
    {
        int remainder = temp % 2;

        binaryNumber += remainder * pow (10, exponent);

        ++exponent;
        temp /= 2;
    }

    std::cout << binaryNumber << std::endl;

    return 0;
}