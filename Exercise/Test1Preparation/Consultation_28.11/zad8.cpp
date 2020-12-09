#include <iostream>

int main ()
{
    size_t size;

    do
    {
        std::cin >> size;

    } while (size < 5 || size > 25);
    
    int arr[25];

    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    for (int i = 0; i < size-1; ++i)
    {
        if (arr[i] == arr[i+1] || arr[i] == -arr[i+1])
        {
            std::cout << arr[i] << ", " << arr[i+1] << std::endl;
        }
    }

    return 0;
}