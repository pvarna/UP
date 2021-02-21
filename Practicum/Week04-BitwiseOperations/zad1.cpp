#include <iostream>

int main ()
{
    int number, shiftedNumber;

    std::cin >> number; // 72(10) = 01001000(2)

    shiftedNumber = number >> 1; // 01001000 --> 00100100

    if ((number & shiftedNumber) == 0)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    
    return 0;
}

/*
    01001000
   &
    00100100
    --------
    00000000 --> true 

    1100
   &
    0110
    ----
    0100 --> false

*/