#include <iostream>

int main ()
{
    int n, firstDigit, secondDigit, thirdDigit;

    std::cin >> n;

    thirdDigit = n % 10;
    secondDigit = n / 10 % 10;
    firstDigit = n / 100;

    if (firstDigit == thirdDigit)
    {
        std::cout << "The number is a palindrom" << std::endl;
    }
    else 
    {
        std::cout << "The number isn't a palindrom" << std::endl;
    }
    return 0;
}