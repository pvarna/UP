#include <iostream>

bool areDigitsOnEvenPositionsEven (int number);

int main ()
{
    int m, n, counter = 0;

    std::cin >> m >> n;

    for (int i = m; i < n; ++i)
    {
        if(areDigitsOnEvenPositionsEven(i))
        {
            ++counter;
        }
    }

    std::cout << counter << std::endl;

    return 0;
}

bool areDigitsOnEvenPositionsEven (int number)
{
    int temp = number, pos = 1;
    while (temp)
    {
        if (((temp % 10) % 2) != (pos % 2))
        {
            return false;
        }
        ++pos;
        temp /= 10;
    }
    return true;    
}