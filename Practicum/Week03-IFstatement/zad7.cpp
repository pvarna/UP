#include <iostream>

int main ()
{
    int x, y;

    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;


    if(x >= y)
    {
        std::cout << x << std::endl << y << std::endl;
    }
    else
    {
        std::cout << y << std::endl << x << std::endl;
    }

    return 0;
}