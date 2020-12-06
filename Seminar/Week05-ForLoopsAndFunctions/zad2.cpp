#include <iostream>

int main ()
{
    int n;

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cout << i*i + 3*i << std::endl;
    }

    return 0;
}