#include <iostream>

int main ()
{
    int m, n;

    std::cin >> m >> n;

    for (int i = 0; i < (m + (n-1)*(m-1)); ++i)
    {
        std::cout << "* ";
    }
    std::cout << std::endl;
    for (int j = 0; j < m-2; ++j)
    {
        for (int i = 0; i < (m + (n-1)*(m-1)); ++i)
        {
            if (i % (m-1) == 0)
            {
                std::cout << "* ";
            }
            else
            {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < (m + (n-1)*(m-1)); ++i)
    {
        std::cout << "* ";
    }
    return 0;
}