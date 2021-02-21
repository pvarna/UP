#include <iostream>

int main ()
{
    int n, firstDigit, secondDigit, thirdDigit;

    std::cin >> n;

    thirdDigit = n % 10;
    secondDigit = n / 10 % 10;
    firstDigit = n / 100;

    int sum = firstDigit + secondDigit + thirdDigit;
    int maxDigit = firstDigit, minDigit = firstDigit;

    if(secondDigit > maxDigit)
    {
        maxDigit = secondDigit;
    }
    if(thirdDigit > maxDigit)
    {
        maxDigit = thirdDigit;
    }
    if(secondDigit < minDigit)
    {
        minDigit = secondDigit;
    }
    if(thirdDigit < minDigit)
    {
        minDigit = thirdDigit;
    }

    std::cout << minDigit << " " << sum - (minDigit + maxDigit) << " " << maxDigit << std::endl;

    return 0;
}