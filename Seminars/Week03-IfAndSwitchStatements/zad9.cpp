#include <iostream>

int main ()
{
    int n;

    std::cin >> n;
    
    switch (n % 2)
    {
    case 0:
        std::cout << "even" << std::endl;
        break;
    case 1:
        std::cout << "odd" << std::endl;
        break;
    }

    return 0;
}