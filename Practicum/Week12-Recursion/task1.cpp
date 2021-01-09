#include <iostream>

void printInReverseOrder(int n);

int main ()
{
    int n;

    std::cin >> n;
    printInReverseOrder(n);

    return 0;
}

void printInReverseOrder(int n)
{
    if (n == 0)
    {
        return;
    }
    std::cout << n << " ";
    printInReverseOrder(n-1);
}