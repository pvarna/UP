#include <iostream>

int main ()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    if(n <= 9)
    {
        std::cout << 22 + n << ".01.2020" << std::endl;
    }
    else
    {
        std::cout << n - 9 << ".02.2020" << std::endl;
    }
    
    return 0;
}