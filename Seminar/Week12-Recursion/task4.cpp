#include <iostream>

int calculateSum(int n, int k, int sum, int start);

int main ()
{
    int n, k;

    std::cin >> n >> k;

    std::cout << calculateSum(n, k, 0, 1) << std::endl;

    return 0;
}

int calculateSum(int n, int k, int sum, int start)
{
    if (start > n)
    {
        return sum;
    }
    sum += start;
    start += k;
    return calculateSum(n, k, sum, start);
}