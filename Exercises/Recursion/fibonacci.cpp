#include <iostream>

unsigned long long int fibonacci(unsigned n);

unsigned long long int fibonacciTail(unsigned n, unsigned long long f1, unsigned long long f2);

unsigned long long int fibonacciTailWrapper(unsigned n);

int main ()
{
    for (int i = 1; i < 50; ++i)
    {
        std::cout << fibonacciTailWrapper(i) << std::endl;
    }


    //std::cout << fibonacciTailWrapper(6) << std::endl;

    return 0;
}

unsigned long long int fibonacci(unsigned n)
{
    if (n < 2)
    {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

unsigned long long int fibonacciTail(unsigned n, unsigned long long f1, unsigned long long f2)
{
    if (n == 1)
    {
        return f1 + f2;
    }
    return fibonacciTail(n-1, f1 + f2, f1);
}

unsigned long long int fibonacciTailWrapper(unsigned n)
{
    return fibonacciTail(n, 1, 0);
}