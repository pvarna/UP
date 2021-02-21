#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t getSizeOfArray ();

void insertArrayElements (int numbers[], size_t size);

void printArray (int numbers[], size_t size);

void rightShiftElementsOfArray (int numbers[], size_t size);

int main ()
{
    int numbers[MAX_ARRAY_SIZE] = {};
    size_t size;
    int positions;

    size = getSizeOfArray();
    insertArrayElements(numbers, size);
    std::cin >> positions;
    

    for (int i = 0; i < (positions % size); ++i)
    {
        rightShiftElementsOfArray (numbers, size);
    }

    printArray(numbers, size);

    return 0;
}

size_t getSizeOfArray ()
{
    size_t size;

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

void printArray (int numbers[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

void rightShiftElementsOfArray (int numbers[], size_t size)
{
    int lastElement = numbers[size-1];

    for (int i = size-1; i > 0; --i)
    {
        numbers[i] = numbers[i-1];
    }

    numbers[0] = lastElement;
}