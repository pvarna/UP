#include <iostream>

int main ()
{
    int num1, num2, num3;

    std::cin >> num1 >> num2 >> num3;

    int maxNum = num1;

    if (num2 > maxNum)
    {
        maxNum = num2;
    }
    if (num3 > maxNum)
    {
        maxNum = num3;
    }

    std::cout << maxNum << std::endl;

    return 0;
}