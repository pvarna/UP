#include <iostream>
#include <cmath>

struct Point
{
    double x;
    double y;
};

void readPoint(Point& point);

void printPoint(Point point);

double distanceFromCenterToPoint(Point point);

double distnceBetweenTwoPointers(Point point1, Point point2);

int main ()
{
    Point point1, point2;

    readPoint(point1);
    printPoint(point1);

    readPoint(point1);
    printPoint(point1);

    std::cout << "Distance from Point 1 to the center: " << distanceFromCenterToPoint(point1) << std::endl;
    std::cout << "Distance from Point 2 to the center: " << distanceFromCenterToPoint(point2) << std::endl;

    std::cout << "Distance between the points: " << distnceBetweenTwoPointers(point1, point2) << std::endl;

    return 0;
}

void readPoint(Point& point)
{
    std::cin >> point.x >> point.y;
}

void printPoint(Point point)
{
    std::cout << "x = " << point.x << std::endl;
    std::cout << "y = " << point.y << std::endl;
}

double distanceFromCenterToPoint(Point point)
{
    return sqrt(point.x*point.x+point.y*point.y);
}

double distnceBetweenTwoPointers(Point point1, Point point2)
{
    double width, height;
    width = fabs(point1.x - point2.x);
    height = fabs(point2.x - point2.x);

    return sqrt((width)*(width)+(height)*(height));
}