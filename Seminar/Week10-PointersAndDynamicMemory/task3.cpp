#include <iostream>

int * createArray(size_t size);

int main ()
{
    size_t size;

    std::cin >> size;

    createArray(size);

    int * numbers = createArray(size);

    for (size_t i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << numbers[i] << " ";
    }

    delete[] numbers;

    return 0;
}

int * createArray(size_t size)
{
    int * array = new(std::nothrow) int[size];
    if(!array)
    {
        return array;
    }
    return array;
}