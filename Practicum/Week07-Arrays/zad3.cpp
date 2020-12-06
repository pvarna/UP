#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t input (int numbers[]);

void printArray (int numbers[], size_t size);

void reverseArray1 (int numbers[], size_t size);

void reverseArray2 (int numbers[], size_t size);

void swap (int &a, int &b);

int main ()
{
    int numbers[MAX_ARRAY_SIZE];
    size_t size = input(numbers);

    reverseArray2(numbers, size);

    printArray(numbers, size);
    
    return 0;
}

size_t input (int numbers[])
{
    size_t size;

    std::cin >> size;

    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }

    return size;
}

void reverseArray1 (int numbers[], size_t size)
{
    int reversedArray[size] = {};
    int counter = 0;

    for (int i = size - 1; i >=0; --i)
    {
        reversedArray[counter] = numbers[i];
        ++counter;
    }

    for (int i = 0; i < size; ++i)
    {
        numbers[i] = reversedArray[i];
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

void swap (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void reverseArray2 (int numbers[], size_t size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        swap(numbers[i], numbers[size-i-1]);
    }
}