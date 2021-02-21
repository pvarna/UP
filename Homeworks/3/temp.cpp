#include <iostream>

int main ()
{
    unsigned char test[5];

    for (int i = 0; i < 5; ++i)
    {
        std::cin >> test[i];
    }

    for (int i = 0; i < 5; ++i)
    {
        std::cout << test[i] << " ";
    }

    return 0;
}