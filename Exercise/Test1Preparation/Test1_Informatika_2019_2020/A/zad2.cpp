#include <iostream>

bool areSumAndProductOfDigitsEqual (int number);

int main ()
{
    int a, b, counter = 0;

    std::cin >> a >> b;

    for (int i = a; i < b; ++i)
    {
        if (areSumAndProductOfDigitsEqual(i))
        {
            ++counter;
        }
    }

    std::cout << counter << std::endl;

    return 0;
}

bool areSumAndProductOfDigitsEqual (int number)
{
    int sum = 0, product = 1;
    while (number)
    {
        sum += (number % 10);
        product *= (number % 10);
        number /= 10;
    }
    if (sum == product)
    {
        return true;
    }
    return false;
}