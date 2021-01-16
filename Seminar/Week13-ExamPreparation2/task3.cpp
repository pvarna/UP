#include <iostream>

bool isNum2InNum1(int number1, int number2);

int main ()
{
    int number1, number2;

    std::cin >> number1 >> number2;

    std::cout << std::boolalpha << isNum2InNum1(number1, number2) << std::endl;

    return 0;
}

bool isNum2InNum1(int number1, int number2)
{
    if (number2 == 0)
    {
        return true;
    }

    if (number1 == 0)
    {
        return false;
    }

    if (number1 % 10 == number2 % 10)
    {
        number2 /= 10;
    }
    return isNum2InNum1(number1/10, number2);
}