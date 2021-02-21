#include <iostream>

int main ()
{
    int number;

    std::cin >> number;

    //7 = 4 + 2 + 1;

    std::cout << (number << 2) + (number << 1) + (number) << std::endl; 

    return 0;
}