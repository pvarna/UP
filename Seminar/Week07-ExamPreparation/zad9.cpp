#include <iostream>

void removeDigitOnGivenPosition (int &number, int k);

int getLengthOfNumber (int number);

int main ()
{
    int number, k;

    std::cin >> number >> k;
    
    removeDigitOnGivenPosition(number, k);

    std::cout << number << std::endl;

    return 0;
}

int getLengthOfNumber (int number)
{
    int length = 0;
    while (number)
    {
        ++length;
        number /= 10;
    }

    return length;
}

void removeDigitOnGivenPosition (int &number, int k)
{
    int position = getLengthOfNumber(number) - k + 1;
    int temp = 0;
    int counter = 1;
    while (number)
    {
        if (counter != position)
        {
            temp *= 10;
            temp += (number % 10);
        }
        ++counter;
        number /= 10;
    }
    while (temp)
    {
        number *= 10;
        number += (temp % 10);
        temp /= 10;
    }
}