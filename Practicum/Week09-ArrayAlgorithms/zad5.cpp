#include <iostream>
#include <cmath>

double decimalToOctal(int number);

int main ()
{
    int n, binaryDigit, decimalNumber = 0;

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> binaryDigit;
        if (binaryDigit == 1)
        {
            decimalNumber += pow(2.0, (double)(n-1-i));
        }
    }

    std::cout << decimalToOctal(decimalNumber) << std::endl;

    return 0;
}

double decimalToOctal(int number)
{
    double exponent = 0;
    int temp = number;
    double octalNumber = 0;

    while (temp)
    {
        int remainder = temp % 8;

        octalNumber += remainder * pow(10.0, (double)exponent);
        ++exponent;
        temp /= 8;
    }

    return octalNumber;
}
