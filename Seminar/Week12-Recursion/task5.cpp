#include <iostream>

int calculateProduct(int n, int k, int product, int start);

int main ()
{
    int n, k;

    std::cin >> n >> k;

    std::cout << calculateProduct(n, k, 1, 1) << std::endl;

    return 0;
}

int calculateProduct(int n, int k, int product, int start)
{
    if (start > n)
    {
        return product;
    }
    product *= start;
    start += k;
    return calculateProduct(n, k, product, start);
}