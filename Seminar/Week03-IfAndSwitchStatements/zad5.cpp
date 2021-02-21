#include <iostream>

int main ()
{
    int n;

    std::cin >> n;

    if (n < 2211 || n > 8999)
    {
        std::cout << "Invalid number" << std::endl;
    }
    else
    {
        int m, firstDigit, secondDigit, thirdDigit, fourthDigit, br = 0;

        std::cin >> m;

        fourthDigit = n % 10;
        thirdDigit = n / 10 % 10;
        secondDigit = n / 100 % 10;
        firstDigit = n / 1000;

        if(m == firstDigit) br++;
        if(m == secondDigit) br++;
        if(m == thirdDigit) br++;
        if(m == fourthDigit) br++;

        std::cout << br << std::endl;
    }
    

    return 0;
}