#include <iostream>

int main()
{
    int k, firstDigit, secondDigit, thirdDigit, sumOfDigits;

    std::cin >> k;

    thirdDigit = k % 10;
    secondDigit = k / 10 % 10;
    firstDigit = k / 100;

    sumOfDigits = firstDigit + secondDigit + thirdDigit;

    std::cout << sumOfDigits << std::endl;

    return 0;
}