#include <iostream>

int findMaxElement(int* array, int size, int max);

int findMaxElementWrapper(int* array, int size);

int main ()
{
    int n;

    std::cin >> n;

    int* numbers = new(std::nothrow) int[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    std::cout << findMaxElementWrapper(numbers, n) << std::endl;

    return 0;
}

int findMaxElement(int* array, int size, int max)
{
    if (size == 0)
    {
        return max;
    }
    if(*array > max)
    {
        max = *array;
    }
    return findMaxElement(array+1, size-1, max);
}

int findMaxElementWrapper(int* array, int size)
{
    return findMaxElement(array+1, size-1, *array);
}