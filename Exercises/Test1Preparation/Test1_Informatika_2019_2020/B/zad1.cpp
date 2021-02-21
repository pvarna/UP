#include <iostream>
#include <cmath>

double calculateSide (double x1, double y1, double x2, double y2);

const double EPS = 1.0/(1<<30);  // Comparison error threshold

int main ()
{
    double x1, x2, x3, y1, y2, y3;
    double side1, side2, side3;

    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    side1 = calculateSide (x1, y1, x2, y2);
    side2 = calculateSide (x1, y1, x3, y3);
    side3 = calculateSide (x2, y2, x3, y3);

    //std::cout << side1 << " " << side2 << " " << side3 << std::endl;

    double maxSide = std::max(side1, std::max(side2, side3));
    double minSide = std::min(side1, std::min(side2, side3));
    double middleSide = (side1 + side2 + side3) - (minSide + maxSide);

    //std::cout << minSide << " " << middleSide << " " << maxSide << std::endl;

    if (minSide + middleSide <= maxSide)
    {
        std::cout << "There is no such triangle" << std::endl;
    }
    else
    {
        if (fabs(((minSide * minSide) + (middleSide * middleSide)) - (maxSide * maxSide)) < EPS)
        {
            std::cout << "Yes" << std::endl;
            //std::cout << ((minSide * minSide) + (middleSide * middleSide)) - (maxSide * maxSide) << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
            //std::cout << ((minSide * minSide) + (middleSide * middleSide)) - (maxSide * maxSide) << std::endl;
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