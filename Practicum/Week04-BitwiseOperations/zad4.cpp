#include <iostream>

int main()
{
    int number;

    std::cin >> number;

    if ((number & (number - 1)) == 0)
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
/*
    16    = 10000
    15    = 01111
    16&15 = 00000
*/