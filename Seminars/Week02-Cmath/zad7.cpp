#include <iostream>
#include <cmath>

int main ()
{
    int firstNumber, secondNumber, maxNumber = 0;

    std::cin >> firstNumber >> secondNumber;

    maxNumber = firstNumber >= secondNumber ? firstNumber : secondNumber;

    std::cout << pow((double)maxNumber, 3.0) << std::endl;

    return 0;
}