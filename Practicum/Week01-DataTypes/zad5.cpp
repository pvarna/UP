#include <iostream>

int main ()
{
    int firstNumber, secondNumber, temp;
    std::cin >> firstNumber >> secondNumber;

    temp = firstNumber;
    firstNumber = secondNumber;
    secondNumber = temp;

    std::cout << firstNumber << " " << secondNumber << std::endl;

    return 0;
}
