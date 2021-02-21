#include <iostream>

int main ()
{
    int xCoordinate, yCoordinate;

    std::cout << "Enter X-coordinate: ";
    std::cin >> xCoordinate;

    std::cout << "Enter Y-coordinate: ";
    std::cin >> yCoordinate;

    if(xCoordinate == 0 && yCoordinate == 0)
    {
        std::cout << "The point lies on the center of the coordinate system" << std::endl;
    }
    else if(xCoordinate == 0 && yCoordinate != 0)
    {
        std::cout << "The point lies on the Y-axis of the coordinate system" << std::endl;
    }
    else if(xCoordinate != 0 && yCoordinate == 0)
    {
        std::cout << "The point lies on the X-axis of the coordinate system" << std::endl;
    }
    else if(xCoordinate > 0 && yCoordinate > 0)
    {
        std::cout << "The point is in first quadrant" << std::endl;
    }
    else if(xCoordinate < 0 && yCoordinate > 0)
    {
        std::cout << "The point is in second quadrant" << std::endl;
    }
    else if(xCoordinate < 0 && yCoordinate < 0)
    {
        std::cout << "The point is in third quadrant" << std::endl;
    }
    else if(xCoordinate > 0 && yCoordinate < 0)
    {
        std::cout << "The point is in fourth quadrant" << std::endl;
    }
    return 0;
}