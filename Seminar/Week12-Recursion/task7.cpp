#include <iostream>

bool isPrime(int number, int divider);

int sumPrimes(int a, int b, int current, int sum);

int main ()
{
    int a, b;

    std::cin >> a >> b;

    std::cout << sumPrimes(a, b, a, 0);

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

int sumPrimes(int a, int b, int current, int sum)
{
    if (current == b)
    {
        return sum;
    }
    if (isPrime(current, 2))
    {
        sum += current;
    }
    ++current;
    return sumPrimes(a, b, current, sum);
}