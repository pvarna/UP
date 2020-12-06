#include <iostream>

int main ()
{
    double x, y, z;

    std::cin >> x >> y >> z;

    std::cout << ((x*y)*(y-z))/z << std::endl;

    return 0;
}