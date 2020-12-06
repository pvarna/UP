#include <iostream>

int main ()
{
    int f1 = 1, f2 = 1;

    std::cout << f1 << std::endl << f2 << std::endl;

    for (int i = 0; i < 11; i++)
    {
        int fNext = f1 + f2;

        std::cout << fNext << std::endl;

        f1 = f2;
        f2 = fNext;
    }
    
    return 0;
}