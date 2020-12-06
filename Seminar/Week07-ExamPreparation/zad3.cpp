#include <iostream>

bool isNumberPowerOfTwo (int number);

int main ()
{
    int n;
    
    std::cin >> n;

    if(isNumberPowerOfTwo(n))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    return 0;
}

bool isNumberPowerOfTwo (int number)
{
    int counter = 0;
    while (number > 1)
    {
        if (number & 2 != 0)
        {
            return false;
        }
        number /= 2;
        ++counter;
    }
    std::cout << "2^" << counter << std::endl;

    return true;
}