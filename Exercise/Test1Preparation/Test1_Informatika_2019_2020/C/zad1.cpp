#include <iostream>
#include <cmath>

const double EPS = 1.0/(1<<30); // comparison error threshold

int main ()
{
    double a1, b1, c1, a2, b2, c2;
    double x, y;

    std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    /* A LOOOOOOOT OF CHECKS IF A1, A2, B1, B2, C1 AND/OR C2 ARE 0 OR NOT 
    if (fabs(a1) < EPS && fabs(a2) < EPS && fabs(b1) < EPS && fabs(b2) < EPS)
    {
        if (fabs(c1) < EPS && fabs(c2) < EPS)
        {
            std::cout << "All numbers are solutions" << std::endl;
        }
        else
        {
            std::cout << "No solution" << std::endl;
        }
    }
    else if (fabs(a1) < EPS && fabs(a2) < EPS)
    {
        if (fabs(b1) >= EPS && fabs(b2) >= EPS)
        {
            double y1 = - (c1 / b1);
            double y2 = - (c2 / b2);
            if (fabs(y1 - y2) < EPS)
            {
                std::cout << "The solution doesn't depend on X, Y = " << y1 << std::endl;
            }
            else
            {
                std::cout << "No solution" << std::endl;
            }
        }
        else
        {
            std::cout << "No solution" << std::endl;
        }
    }
    else if (fabs(b1) < EPS && fabs(b2) < EPS)
    {
        if (fabs(a1) >= EPS && fabs(a2) >= EPS)
        {
            double x1 = - (c1 / a1);
            double x2 = - (c2 / a2);
            if (fabs(x1 - x2) < EPS)
            {
                std::cout << "The solution doesn't depend on Y, X = " << x1 << std::endl;
            }
            else
            {
                std::cout << "No solution" << std::endl;
            }
        }
        else
        {
            std::cout << "No solution" << std::endl;
        }
    }
    else if (fabs(a1) >= EPS && fabs(a2) < EPS)
    {
        if (fabs(b1) >= EPS && fabs(b2) >= EPS)
        {
            y = - (c2 / b2);
            x = (- c1 - y * b1) / a1;\
            std::cout << "X = " << x << ", Y = " << y << std::endl;
        }
        else
        {
            std::cout << "No solution" << std::endl;
        }
    }
    .....................................................................
    */

    double quotientOfA = a2 / a1;

    a1 *= quotientOfA;
    b1 *= quotientOfA;
    c1 *= quotientOfA;

    b2 -= b1;
    c2 -= c1;

    if (fabs(b2) < EPS && fabs(c2) < EPS)
    {
        std::cout << "All numbers are solutions" << std::endl;
    }
    else if (fabs(b2) < EPS && fabs(c2) > EPS)
    {
        std::cout << "No solution" << std::endl;
    }
    else
    {
        y = - (c2 / b2);
        x = (- c1 - b1 * y) / a1; 

        std::cout << "X = " << x << ", Y = " << y << std::endl;   
    }

    return 0;
}