#include <iostream>

double calculate(double x, int n, double sum, int current);

int main ()
{
    double x;
    int n;

    std::cin >> x;
    std::cin >> n;

    std::cout << calculate(x, n, 0, 0);
}

double calculate(double x, int n, double sum, int current)
{
    if (current == n)
    {
        return sum;
    }
    ++current;
    sum = sum*x + current;
    return calculate(x, n, sum, current);
}