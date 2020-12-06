#include <iostream>

int main ()
{
    int number, pos1, pos2;

    std::cin >> number >> pos1 >> pos2; //28 0 3 28(10) = 11100(2)

    int shiftedPos1 = 1 << pos1; // 00001 ---> 00001
    int shiftedPos2 = 1 << pos2; // 00001 ---> 01000

    int shiftedPos = (shiftedPos1 | shiftedPos2); // (00001 | 01000) ---> 01001

    std::cout << (shiftedPos ^ number) << std::endl;

    return 0;
}

/*
    01001
   ^
    11100
    -----
    10101
*/