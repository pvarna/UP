#include <iostream>

int main ()
{
    int number, firstDigit, secondDigit, thirdDigit;

    std::cout << "Enter a number: ";
    std::cin >> number;

    thirdDigit = number % 10;
    secondDigit = number / 10 % 10;
    firstDigit = number / 100;

    if(firstDigit < secondDigit && secondDigit < thirdDigit)
    {
        std::cout << "TRUE" << std::endl;
    }
    else
    {
        std::cout << "FALSE" << std::endl;
    }
    
    return 0;
}