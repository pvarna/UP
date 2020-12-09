#include <iostream>

double sumElements (double arr[], size_t size);

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

    std::cout << sumElements(arr, n) << std::endl; 

    return 0;
}

double sumElements (double arr[], size_t size)
{
    double minEl = arr[0], maxEl = arr[0];
    double sum = arr[0];
    for (int i = 1; i < size; ++i)
    {
        sum += arr[i];

        if (arr[i] > maxEl)
        {
            maxEl = arr[i];
        }

        if (arr[i] < minEl)
        {
            minEl = arr[i];
        }
    }

    return minEl + maxEl + (sum / size);
}