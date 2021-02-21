#include <iostream>

int main ()
{
    int firstNumber, secondNumber;
    bool isFirstBiggerThanSecond;

    std::cin >> firstNumber >> secondNumber;

    isFirstBiggerThanSecond = firstNumber == secondNumber * 2 ? true : false;

    std::cout << std::boolalpha << isFirstBiggerThanSecond << std::endl;

    return 0;
}