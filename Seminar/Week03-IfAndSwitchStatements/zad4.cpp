#include <iostream>

int main ()
{
    int a, b;

    std::cin >> a >> b;

    if(a == b)
    {
        std::cout << "The rectangle is squire." << std::endl;
    }

    std::cout << "Perimeter: " << 2 * (a + b) << std::endl;
    std::cout << "Area: " << a * b << std::endl;
    
    return 0;
}