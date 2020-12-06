#include <iostream>

int main ()
{
    const double PI = 3.14;
    double radius;

    std::cin >> radius;

    std::cout << "Perimeter: " << 2 * PI * radius << std::endl;
    std::cout << "Area: " << PI * radius * radius << std::endl;

    return 0;
}