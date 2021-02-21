#include <iostream>

unsigned long long int factoriel(unsigned n);

int main ()
{
    std::cout << factoriel(6) << std::endl;

    return 0;
}

unsigned long long int factoriel(unsigned n)
{
    if (n == 0)
    {
        return 1;
    }
    return n*factoriel(n-1);
}