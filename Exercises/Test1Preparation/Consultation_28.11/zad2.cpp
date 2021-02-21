#include <iostream>

int main ()
{
    size_t n;
    double arr[1000];

    do
    {
        std::cin >> n;

    } while (n > 1000);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    
    for (int i = n-1; i >=0; --i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}