#include <iostream>

int main ()
{
    int n;

    std::cin >> n;

    int temp = n;

    while (temp)
    {
        int digit = temp % 10;
        std::cout << digit << " ";

        for (int i = 0; i < digit; ++i)
        {
            std::cout << "#";
        }

        std::cout << std::endl;
        
        temp /= 10;
    }

    return 0;
}