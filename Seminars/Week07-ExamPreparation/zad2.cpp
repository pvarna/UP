#include <iostream>

void getMinAndMaxDigit (int number, int &min, int &max);

int main ()
{
    int number, minDigit = 9, maxDigit = 0;

    std::cin >> number;

    getMinAndMaxDigit(number, minDigit, maxDigit);

    std::cout << minDigit << " " << maxDigit << std::endl;

    return 0;
}

void getMinAndMaxDigit (int number, int &min, int &max)
{
    while (number)
    {
        int lastDigit = number % 10;

        if (lastDigit < min)
        {
            min = lastDigit;
        }
        if (lastDigit > max)
        {
            max = lastDigit;
        }

        number /= 10;
    }
}