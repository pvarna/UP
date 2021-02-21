#include <iostream>

int main ()
{
    int number, position;

    std::cin >> number >> position; // 15 2

    int shiftedNumber = 1 << position; // 0001 ---> 0100

    int oppositeNumber = ~ shiftedNumber; // 0100 ---> 1011

    std::cout << (number & oppositeNumber) << std::endl;

    return 0;
}

/*
    1011
   &
    1111
    ----
    1011
*/