#include <iostream>

int main ()
{
    int nNumber;
    int *pPointer;

    nNumber = 15;
    pPointer = &nNumber;

    std::cout << "nNumber is equal to: " << nNumber << std::endl;
    std::cout << "pPointer is equal to: " << pPointer << std::endl;

    *pPointer = 25;

    std::cout << "nNumber is equal to: " << nNumber << std::endl;

    return 0;
}