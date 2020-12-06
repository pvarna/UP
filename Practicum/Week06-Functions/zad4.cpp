#include <iostream>

bool doesNumberContainTwoConsecutiveEqualDigits (int number); 

int main ()
{
    int k, l;

    std::cin >> k >> l;

    for (int i = k; i <= l; ++i)
    {
        if (doesNumberContainTwoConsecutiveEqualDigits(i))
        {
            std::cout << i << " ";
        }
    }

    return 0;
}

bool doesNumberContainTwoConsecutiveEqualDigits (int number)
{
    int temp = number;

    while (temp > 9)
    {
        int firstDigit = temp % 10;
        int secondDigit = temp / 10 % 10;
        if (firstDigit == secondDigit)
        {
            return true;
        }
        temp /= 10;
    }
    return false;
}