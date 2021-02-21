#include <iostream>

int numberOfZeroes (int number);

int main ()
{
    int n, number, maxZeroes, numberWithMostZeroes;

    std::cin >> n;

    std::cin >> number;
    maxZeroes = numberOfZeroes(number);
    numberWithMostZeroes = number;
    for (int i = 1; i < n; ++i)
    {
        std::cin >> number;

        if(numberOfZeroes(numberWithMostZeroes) > maxZeroes)
        {
            maxZeroes = numberOfZeroes(i);
            numberWithMostZeroes = number;
        }
    }

    std::cout << maxZeroes << " " << numberWithMostZeroes << std::endl;

    return 0;
}

int numberOfZeroes (int number)
{
    int counter = 0, temp = number;

    if (temp == 0)
    {
        return 1;
    }

    while (temp)
    {
        if (temp % 10 == 0)
        {
            ++counter;
        }

        temp /= 10;
    }
    return counter;
}