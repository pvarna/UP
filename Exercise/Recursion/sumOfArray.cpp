#include <iostream>

int sumR(int* array, size_t size);

int sumL(int* array, size_t size);

int sumTail(int* array, size_t size, int result);

int sumTailWrapper(int* array, size_t size);

int main ()
{
    int numbers[5] = {3, 8, -4, 2, 7};

    std::cout << sumR(numbers, 5) << std::endl;
    std::cout << sumL(numbers, 5) << std::endl;
    std::cout << sumTailWrapper(numbers, 5) << std::endl;

    return 0;
}

int sumR(int* array, size_t size)
{
    if (size == 0)
    {
        return 0;
    }
    return array[size-1] + sumR(array, size-1);
}

int sumL(int* array, size_t size)
{
    if (size == 0)
    {
        return 0;
    }
    return *array + sumR(array+1, size-1);
}

int sumTail(int* array, size_t size, int result)
{
    if (size == 0)
    {
        return result;
    }
    return sumTail(array+1, size-1, result+*array);
}

int sumTailWrapper(int* array, size_t size)
{
    return sumTail(array, size, 0);
}