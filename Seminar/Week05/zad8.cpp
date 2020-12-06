#include <iostream>
#include <cmath>

int factorial (int number);

int main ()
{
    double x, sum = 1;
    int n;

    std::cin >> x >> n;

    for (int i = 1; i <= n; ++i)
    {
        sum += (pow(x,i) / factorial(i));
    }

    std::cout << sum << std::endl;
    
    return 0;
}

int factorial (int number)
{
    int product = 1;

    for (int i = 1; i <= number; ++i)
    {
        product *= i;
    }

    return product;
}