#include <iostream>

int main ()
{
    int m, n, counter = 0;

    std::cin >> m >> n;

    for (int i = m; i <= n; i++)
    {
        if (i % 3 == 0)
        {
            ++counter;
        }
    }

    std::cout << counter << std::endl;

    return 0;
}