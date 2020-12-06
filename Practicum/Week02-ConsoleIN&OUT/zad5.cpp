#include <iostream>
#include <cmath>

int main ()
{
    double l, h, a, areaOfWall;

    std::cin >> l >> h >> a;

    areaOfWall = l * h;

    std::cout << ceil(areaOfWall / a) << " cans of paint are needed" << std::endl;

    return 0;
}