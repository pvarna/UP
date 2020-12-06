#include <iostream>

int main ()
{
    int firstNumber, secondNumber, thirdNumber; 

    std::cout << "Enter the first number: ";
    std::cin >> firstNumber;
    std::cout << "Enter the second number: ";
    std::cin >> secondNumber;
    std::cout << "Enter the third number: ";
    std::cin >> thirdNumber;

    int minNumber = firstNumber, maxNumber = firstNumber;

    if (secondNumber > maxNumber)
    {
        maxNumber = secondNumber;
    }

    if (thirdNumber > maxNumber)
    {
        maxNumber = thirdNumber;
    }

    if (secondNumber < minNumber)
    {
        minNumber = secondNumber;
    }

    if (thirdNumber < minNumber)
    {
        minNumber = thirdNumber;
    }

    std::cout << "Max number is " << maxNumber << " and min number is " << minNumber << std::endl;

    return 0;
}