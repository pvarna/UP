#include <iostream>

int main ()
{
    int number, counter = 0;

    std::cin >> number;

    while (number)
    {
        ++counter;
        number /= 10;
    }
    
    std::cout << counter << std::endl;

    return 0;
}