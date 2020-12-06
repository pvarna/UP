#include <iostream>

int main()
{
    int k, firstDigit, secondDigit, thirdDigit, kReversed;

    std::cin >> k;

    thirdDigit = k % 10;
    secondDigit = k / 10 % 10;
    firstDigit = k / 100;

    kReversed = 100 * thirdDigit + 10 * secondDigit + firstDigit;

    //std::cout << firstDigit << " " << secondDigit << " " << thirdDigit << std::endl;
    
    std::cout << kReversed << std::endl;

    return 0;
}