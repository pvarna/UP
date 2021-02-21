#include <iostream>

int main()
{
    int firstSide, secondSide, thirdSide;

    std::cout << "Enter the first side: ";
    std::cin >> firstSide;
    std::cout << "Enter the second side: ";
    std::cin >> secondSide;
    std::cout << "Enter the third side: ";
    std::cin >> thirdSide;

    if(firstSide == secondSide && secondSide == thirdSide)
    {
        std::cout << "Triangle is equilateral" << std::endl;
    }
    else if(firstSide != secondSide && firstSide != thirdSide && secondSide != thirdSide)
    {
        std::cout << "Triangle is multifaceted" << std::endl;
    }
    else
    {
        std::cout << "Triangle is isosceles" << std::endl;
    }
    

    return 0;
}