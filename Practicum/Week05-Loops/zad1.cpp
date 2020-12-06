#include <iostream>

int main ()
{
    int counter = 1, number = 2;

    while (counter <= 20)
    {
        std::cout << number << std::endl;

        number += 2;
        ++ counter;
    }

    return 0;
}