#include <iostream>

int main ()
{
    long long n;
    int arr[10] = {0, };

    std::cin >> n;

    if (n < 0)
    {
        n = -n;
    }

    while (n)
    {
        int temp = n % 10;
        ++arr[temp];
        n /= 10;
    }
    
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " - " << arr[i] << std::endl;
    }

    return 0;
}