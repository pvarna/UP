#include <iostream>

int main ()
{
    int number, firstDigit, secondDigit, thirdDigit;

    std::cout << "Enter a number: ";
    std::cin >> number;

    thirdDigit = number % 10;
    secondDigit = number / 10 % 10;
    firstDigit = number / 100;

    if((firstDigit == secondDigit) || (firstDigit == thirdDigit) || (secondDigit == thirdDigit))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    

    return 0;
}