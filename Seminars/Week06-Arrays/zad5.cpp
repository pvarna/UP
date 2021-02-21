#include <iostream>

const int MAX_ARRAY_SIZE = 1000;

size_t getSizeOfArray ();

void printArray (int numbers[], size_t size);

int main ()
{
    int numbers[MAX_ARRAY_SIZE] = {};
    int element = 0;
    size_t size = getSizeOfArray();

    for (unsigned i = 0; i < size; ++i)
    {
        numbers[i] = element;
        element += 5;
    }

    printArray(numbers, size);

    return 0;
}

size_t getSizeOfArray ()
{
    std::cout << "Insert size of array: ";
    size_t size = 0;
    std::cin >> size;
    return size;
}

void printArray (int numbers[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}