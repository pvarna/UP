#include <iostream>

void printSpaces(unsigned n);

void printNumbersFrom1ToN(unsigned n);

void printNumbersFromNTo1(unsigned n);

void printRow(unsigned k, unsigned n);

void printTriangle(unsigned n, unsigned row);

void triangle(unsigned n); // wrapper

int main ()
{
    /*for (int i = 1; i <= 5; ++i)
    {
        printRow(i, 5);
        std::cout << std::endl;
    }*/
    triangle(9);

    return 0;
}

void printSpaces(unsigned n)
{
    if (n == 0)
    {
        return;
    }
    std::cout << " ";
    printSpaces(n-1);
}

void printNumbersFrom1ToN(unsigned n)
{
    if (n == 0)
    {
        return;
    }
    printNumbersFrom1ToN(n-1);
    std::cout << n << " ";
}

void printNumbersFromNTo1(unsigned n)
{
    if (n == 0)
    {
        return;
    }
    std::cout << n << " ";
    printNumbersFromNTo1(n-1);   
}

void printRow(unsigned k, unsigned n)
{
    printSpaces(2*(n-k));
    printNumbersFrom1ToN(k);
    printNumbersFromNTo1(k-1);
    std::cout << std::endl;
}

void printTriangle(unsigned n, unsigned row)
{
    if (row > n)
    {
        return;
    }
    printRow(row, n);
    printTriangle(n, row+1);
}

void triangle(unsigned n)
{
    printTriangle(n, 1);
}