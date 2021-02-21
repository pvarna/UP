#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t input (int numbers[]);

void sortArray (int numbers[], size_t size); // Bubble Sort

void swap (int &a, int &b);

void printArray (int numbers[], size_t size);

int main ()
{
    int numbers[MAX_ARRAY_SIZE] = {};
    size_t size = input(numbers);

    sortArray(numbers, size);

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

void swap (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortArray (int numbers[], size_t size)
{
    for (int i = 0; i < size-1; ++i)
    {
        for (int j = 0; j < size-1-i; ++j)
        {
            if(numbers[j] > numbers[j+1])
            {
                swap(numbers[j], numbers[j+1]);
            }
        }
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