#include <iostream>

bool areThereSameDigits (int number);

int main ()
{
    int a, b, counter = 0;

    std::cin >> a >> b;
    
    for (int i = a; i < b; ++i)
    {
        if (!areThereSameDigits(i))
        {
            ++counter;
        }
    }

    std::cout << counter << std::endl;

    return 0;
}

bool areThereSameDigits (int number)
{
    while (number)
    {
        int temp = number;
        int digit = temp % 10;
        temp /= 10;
        while (temp)
        {
            if ((temp % 10) == digit)
            {
                return true;
            }
            temp /= 10;
        }
        number /= 10;
    }
    return false;
}