#include <iostream>

void swapValuesOfVariables (int &a, int &b);

int main ()
{
    int number1, number2;

    std::cin >> number1 >> number2;

    swapValuesOfVariables(number1, number2);

    std::cout << number1 << " " << number2 << std::endl;

    return 0;
}

void swapValuesOfVariables (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}