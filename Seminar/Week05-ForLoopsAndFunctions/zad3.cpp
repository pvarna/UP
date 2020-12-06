#include <iostream>

int main ()
{
    for (int i = 7; i > 0; --i)
    {
        for (int j = i; j > 0; --j)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}