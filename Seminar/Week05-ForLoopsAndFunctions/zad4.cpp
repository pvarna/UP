#include <iostream>
#include <cmath>

int numberOfDigits (int number);

int sumOfDigits (int number);

int main ()
{
    int n;

    std::cin >> n;

    if (sumOfDigits(n) == n) // 1-9, 370, 371, 407
    {
        std::cout << "The number is narcissistic" << std::endl;
    }
    else
    {
        std::cout << "The number isn't narcissistic" << std::endl;
    }
    

    return 0;
}

int numberOfDigits (int number)
{
    int temp = number, counter = 0;

    while(temp)
    {
        ++counter;
        temp /= 10;
    }

    return counter;
}

int sumOfDigits (int number)
{
    int temp = number, sum = 0;
    int digits = numberOfDigits(number);

    while(temp)
    {
        sum += pow(temp % 10, digits);
        temp /= 10;
    }

    return sum;
}