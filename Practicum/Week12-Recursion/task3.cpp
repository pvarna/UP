#include <iostream>

int sumOfDigits(int number, int sum);

int sumOfDigitsWrapper(int number);

int main ()
{
    int number;

    std::cin >> number;

    std::cout << sumOfDigitsWrapper(number) << std::endl;

    return 0;
}

int sumOfDigits(int number, int sum)
{
    if (!number)
    {
        return sum;
    }
    sum += (number%10);
    number /= 10;
    return sumOfDigits(number, sum);
}

int sumOfDigitsWrapper(int number)
{
    return sumOfDigits(number, 0);
}