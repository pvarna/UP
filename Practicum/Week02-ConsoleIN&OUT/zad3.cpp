#include <iostream>

int main()
{
    const double PI = 3.14;
    double radius;

    std::cin >> radius;

    std::cout << "The length of the net must be: " << 2 * PI * radius << std::endl;

    return 0;
}