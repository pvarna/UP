#include <iostream>

void minMax(int* arr, size_t size, int*min, int* max);

int main ()
{
    size_t size = 5;
    int* arr = new int[size] {1, 2, 9, 11, 0};
    int min;
    int max;

    minMax(arr, size, &min, &max);

    std::cout << "Min = " << min << std::endl;
    std::cout << "Max = " << max << std::endl;

    return 0;
}

void minMax(int* arr, size_t size, int* min, int* max)
{
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if(*min > arr[i])
        {
            *min = arr[i];
        }
        if(*max < arr[i])
        {
            *max = arr[i];
        }
    }
}