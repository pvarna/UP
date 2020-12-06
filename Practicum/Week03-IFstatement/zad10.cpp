#include <iostream>

int main ()
{
    int firstNumber, secondNumber;
    char arithmeticOperation;

    std::cout << "Enter the first number: ";
    std::cin >> firstNumber;
    std::cout << "Enter the second number: ";
    std::cin >> secondNumber;
    std::cout << "Enter the arithmetic operation: ";
    std::cin >> arithmeticOperation;

    if(arithmeticOperation == '+')
    {
        std::cout << firstNumber + secondNumber << std::endl;
    }
    else if(arithmeticOperation == '-')
    {
        std::cout << firstNumber - secondNumber << std::endl;
    }
    else if(arithmeticOperation == '/')
    {
        std::cout << firstNumber / secondNumber << std::endl;
    }
    else if(arithmeticOperation == '%')
    {
        std::cout << firstNumber % secondNumber << std::endl;
    }
    else if(arithmeticOperation == '*')
    {
        std::cout << firstNumber * secondNumber << std::endl;
    }
    else
    {
        std::cout << "Invalid arithmetic operation" << std::endl;
    }
    

    return 0;
}