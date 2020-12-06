#include <iostream>

//int decimalToBinary (int number);

bool isPalindrome (int number);

int main ()
{
    int k, l;

    std::cin >> k >> l;

    for (int i = k; i <= l; ++i)
    {
        if (isPalindrome(i))
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}

/*int decimalToBinary (int number)
{
    int binaryNumber = 0;
    double exponent = 0;

    int temp = number;

    while (temp)
    {
        int remainder = temp % 2;

        binaryNumber += remainder * pow (10, exponent);

        ++exponent;
        temp /= 2;
    }

    return binaryNumber;
}*/

bool isPalindrome (int number)
{
    int reversedNumber = 0;

    int temp = number;

    while (temp)
    {
        reversedNumber = ((10 * reversedNumber) + (temp % 10));
        temp /= 10;
    }

    if (number == reversedNumber)
    {
        return true;
    }
    return false;
}