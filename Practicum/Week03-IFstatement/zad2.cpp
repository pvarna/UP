#include <iostream>

int main ()
{
    int number, firstDigit, secondDigit, thirdDigit, fourthDigit;

    std::cout << "Enter a number: ";
    std::cin >> number;

    fourthDigit = number % 10;
    thirdDigit = number / 10 % 10;
    secondDigit = number / 100 % 10;
    firstDigit = number / 1000;

    if(fourthDigit == 0)
    {
        std::cout << "There isn't a symmetric number" << std::endl;
    }
    else
    {
        if (firstDigit == fourthDigit && secondDigit == thirdDigit)
        {
            std::cout << "The number is symmetric" << std::endl;
        }
        else
        {
            std::cout << "The number isn't symmetric" << std::endl;
        }    
    }
    return 0;
}