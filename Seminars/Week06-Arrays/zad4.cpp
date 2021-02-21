#include <iostream>

const int MAX_ARRAY_SIZE = 1000;

size_t getSizeOfArray ();

void insertArrayElements (int numbers[], size_t size);

void printReversedArray (int numbers[], size_t size);

int main ()
{
    int numbers [MAX_ARRAY_SIZE] = {};
    size_t size = getSizeOfArray();

    insertArrayElements(numbers, size);
    printReversedArray(numbers, size);

    return 0;
}

size_t getSizeOfArray()
{
    std::cout << "Insert size of array: ";
    size_t size = 0;
    std::cin >> size;
    return size;
}

void insertArrayElements (int numbers[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }
}

void printReversedArray (int numbers[], size_t size)
{
    for (int i = size - 1; i >=0; --i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}