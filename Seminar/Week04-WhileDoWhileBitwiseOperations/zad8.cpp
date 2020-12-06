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

    temp = binaryNumber;
    int sum = 0;

    while (temp)
    {
        int lastDigit = temp % 10;

        sum += lastDigit;

        temp /= 10;
    }
    
    std::cout << sum << std::endl;

    return 0;
}