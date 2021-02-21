#include <iostream>

bool isPrime(int number, int divider);

int main ()
{
    int number;

    std::cin >> number;

    std::cout << std::boolalpha << isPrime(number, 2) << std::endl;

    return 0;
}

bool isPrime(int number, int divider)
{
    if (number == 1)
    {
        return false;
    }
    if (divider == (number / 2 + 1))
    {
        return true;
    }
    if (number % divider == 0)
    {
        return false;
    }
    ++divider;
    return isPrime(number, divider);
}