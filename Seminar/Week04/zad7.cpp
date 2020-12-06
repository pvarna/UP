#include <iostream>
#include <cmath>

int main ()
{
    int x, i;

    std::cin >> x >> i;

    std::cout << ((x >> i) & 1) << std::endl;

    return 0;
}

/*
    11 = 1011
    11 >> 2 ---> 10
    10 &
    01
    --
    00
*/