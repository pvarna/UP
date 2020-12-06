#include <iostream>

int main ()
{
    int n;

    std::cin >> n;

    int temp = n;
    int reversedTemp = 0;

    while (temp)
    {
        reversedTemp *= 10;
        int lastDigit = temp % 10;
        if (lastDigit % 2 == 0)
        {
            reversedTemp += (lastDigit / 2); 
        }
        else
        {
            reversedTemp += lastDigit;
        }
        temp /= 10;
    }

    int result = 0;
    while (reversedTemp) // reversion of the reversed temp
    {
        result *= 10;
        int lastDigit = reversedTemp % 10;
        result += lastDigit;
        reversedTemp /= 10;
    }

    std::cout << result << std::endl;
    
    return 0;
}