#include <iostream>

int main ()
{
    int number, position;

    std::cin >> number >> position; // 15 2

    int shiftedNumber = 1 << position; // 0001 ---> 0100

    shiftedNumber = ~(shiftedNumber); // 0100 ---> 1011

    std::cout << (number & shiftedNumber) << std::endl;

    return 0;
}

/*
    0100
   ^
    1111
    ----
    1011
*/

/*
    1011
    &
    1111
    ----
    1011
*/