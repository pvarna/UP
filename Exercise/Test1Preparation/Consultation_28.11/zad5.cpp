#include <iostream>

int main ()
{
    size_t size;
    int arr[35];

    int sum1 = 0, sum2 = 0;

    do
    {
        std::cin >> size;

    } while (size < 5 || size > 35);

    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
        sum1 += arr[i];
    }

    for (int i = 0; i < size; ++i)
    {
        if (i % 2 == 0)
        {
            arr[i] = (arr[i] / 10) * 10;
        }
        else
        {
            arr[i] = (arr[i] / 10 + 1) * 10;
        }
        sum2 += arr[i];
    }

    std::cout << "sum1 = " << sum1 << std::endl << "sum2 = " << sum2 << std::endl;
    
    return 0;
}