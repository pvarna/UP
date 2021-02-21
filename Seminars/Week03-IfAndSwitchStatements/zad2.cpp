#include <iostream>

int main ()
{
    int n, m, firstDigitN, secondDigitN, thirdDigitN;

    std::cin >> n >> m;

    thirdDigitN = n % 10;
    secondDigitN = n / 10 % 10;
    firstDigitN = n / 100;

    if ((m == firstDigitN) || (m == secondDigitN) || (m == thirdDigitN))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    return 0;
}