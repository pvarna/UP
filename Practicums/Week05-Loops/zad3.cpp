#include <iostream>

int main ()
{
    int number;

    std::cin >> number;

    for (int i = 1; i*i < number; i++)
    {
        std::cout << i*i << " ";
    }

    return 0;
}