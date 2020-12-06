#include <iostream>

int main ()
{
    int n, firstDigit, secondDigit, thirdDigit, sum;

    std::cin >> n;

    thirdDigit = n % 10;
    secondDigit = n / 10 % 10;
    firstDigit = n / 100;

    sum = firstDigit + secondDigit + thirdDigit;

    std::cout << firstDigit << " " << secondDigit << " " << thirdDigit << " " << sum << std::endl;
    
    return 0;
}