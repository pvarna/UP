#include <iostream>

int binarySearch(int* array, size_t left, size_t right, int x);

int binarySearchWrapper(int* array, size_t size, int x);

int main ()
{
    int numbers[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i <= 10; ++i)
    {
        std::cout << binarySearchWrapper(numbers, 5, i) << std::endl;
    }
    return 0;
}

int binarySearch(int* array, size_t left, size_t right, int x)
{
    size_t middle = (left+right)/2;
    if (left >= right)
    {
        return -1;
    }
    if (array[middle] == x)
    {
        return middle;
    }
    else if (array[middle] < x)
    {
        return binarySearch(array, middle+1, right, x);
    }
    return binarySearch(array, left, middle, x);
}

int binarySearchWrapper(int* array, size_t size, int x)
{
    return binarySearch(array, 0, size, x);
}