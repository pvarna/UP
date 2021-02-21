#include <iostream>
#include <cmath>

double binary(int number, double binaryNumber, double exponent);

int main ()
{
    int n;

    std::cin >> n;

    std::cout << binary(n, 0.0, 0.0) << std::endl;

    return 0;
}

double binary(int number, double binaryNumber, double exponent)
{
    if (number == 0)
    {
        return binaryNumber;
    }
    int remainder = number % 2;
    binaryNumber += (remainder * pow(10.0, exponent));
    return binary(number/2, binaryNumber, ++exponent);
}