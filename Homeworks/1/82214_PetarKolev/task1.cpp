#include <iostream>

int main ()
{
    double x1BottomLeftCorner, y1BottomLeftCorner; 
    double width1, height1; 
    double x2BottomLeftCorner, y2BottomLeftCorner; 
    double width2, height2; 

    std::cin >> x1BottomLeftCorner >> y1BottomLeftCorner >> width1 >> height1; 
    std::cin >> x2BottomLeftCorner >> y2BottomLeftCorner >> width2 >> height2; 

    // calculating the coordinates of the top right corners of the rectangles
    double x1TopRightCorner = x1BottomLeftCorner + width1; 
    double y1TopRightCorner = y1BottomLeftCorner + height1;
    double x2TopRightCorner = x2BottomLeftCorner + width2; 
    double y2TopRightCorner = y2BottomLeftCorner + height2;

    // CHECKING IF THE RECTANGLES INTERSECT
    // ************************************
    // checking if one of the rectangles is on the left side of the other one
    if (std::min (x1TopRightCorner, x2TopRightCorner) <= std::max (x1BottomLeftCorner, x2BottomLeftCorner))
    {
        std::cout << 0 << std::endl;
    }
    // checking if one of the rectangles is above the other one
    else if (std::min (y1TopRightCorner, y2TopRightCorner) <= std::max (y1BottomLeftCorner, y2BottomLeftCorner)) 
    {
        std::cout << 0 << std::endl;
    }
    // the rectangles intersect
    else
    {
        // the width of the intersection is equal to the difference between 
        // the smaller X coordinate of the top right corners and the bigger X coordinate of the bottom left corners
        double widthIntersection = (std::min (x1TopRightCorner, x2TopRightCorner) - std::max (x1BottomLeftCorner, x2BottomLeftCorner));

        // the height of the intersection is equal to the difference between 
        // the smaller Y coordinate of the top right corners and the bigger Y coordinate of the bottom left corners
        double heightIntersection = (std::min (y1TopRightCorner, y2TopRightCorner) - std::max (y1BottomLeftCorner, y2BottomLeftCorner));

        double areaIntersection = widthIntersection * heightIntersection; // formula for area of rectangle

        std::cout << areaIntersection << std::endl;
    }

    return 0;
}