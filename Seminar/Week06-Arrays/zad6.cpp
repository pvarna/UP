#include <iostream>

const int MAX_ARRAY_SIZE = 1000;

size_t getSizeOfArray ();

void insertArrayElements (int numbers[], size_t size);

void printArray (int numbers[], size_t size);

void removeGivenElement (int numbers[], size_t &size, int k);

int main ()
{
    int numbers[MAX_ARRAY_SIZE] = {};
    int k;

    size_t size = getSizeOfArray ();
    insertArrayElements(numbers, size);
    std::cout << "Insert k: ";
    std::cin >> k;

    removeGivenElement(numbers, size, k);
    printArray(numbers, size);

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

void printArray (int numbers[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

void removeGivenElement (int numbers[], size_t &size, int k)
{
    for (int i = 0; i < size; ++i)
    {
        if (numbers[i] == k)
        {
            for (int j = i; j < size-1; ++j)
            {
                numbers[j] = numbers[j+1];
            }
            --i;
            --size;
        }
    }
}