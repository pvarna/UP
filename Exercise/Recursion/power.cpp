#include <iostream>

double power(double x, unsigned n); // x^n

double powerTail(double x, unsigned n, double result);

double powerTailWrapper(double x, unsigned n);

int main ()
{
    std::cout << power(2, 10) << std::endl;

    std::cout << powerTailWrapper(2, 12) << std::endl;

    return 0;
}

double power(double x, unsigned n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * power(x, n-1); 
}

double powerTail(double x, unsigned n, double result)
{
    if (n == 0)
    {
        return result;
    }
    return powerTail(x, n-1, result*x);
}

double powerTailWrapper(double x, unsigned n)
{
    return powerTail(x, n, 1);
}