#include <iostream>
#include <cmath>

double calculateSide (double x1, double y1, double x2, double y2);

double calculateArea (double side1, double side2, double side3); // Heron's formula

const double EPS = 1.0/(1<<30);  // Comparison error threshold

int main ()
{
    double x1, x2, x3, y1, y2, y3;
    double side1, side2, side3;

    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    side1 = calculateSide (x1, y1, x2, y2);
    side2 = calculateSide (x1, y1, x3, y3);
    side3 = calculateSide (x2, y2, x3, y3);

    if (side1 < EPS || side2 < EPS || side3 < EPS)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        double area = calculateArea(side1, side2, side3);

        if (area < EPS)
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }   
    }
    
    return 0;
}

double calculateSide (double x1, double y1, double x2, double y2)
{
    double changeInX = fabs(x1 - x2);
    double changeInY = fabs(y1 - y2);

    if (changeInX < EPS && changeInY < EPS)
    {
        return 0;
    }
    if (changeInX < EPS)
    {
        return changeInY;
    }
    if (changeInY < EPS)
    {
        return changeInX;
    }

    return sqrt(changeInX * changeInX + changeInY * changeInY); // right-angled triangle (Pythagoras)
}

double calculateArea (double side1, double side2, double side3)
{
    double semiPerimeter = (side1 + side2 + side3) / 2;
    return sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3));
}