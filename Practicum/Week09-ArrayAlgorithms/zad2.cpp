#include <iostream>

const int MAX_ARRAY_SIZE = 100;

void printArray(int array[], size_t size);

void descendingSelectionSort(int array[], size_t size);

unsigned maxFrom(int array[], unsigned from, unsigned to);

void swap(int array[], unsigned i, unsigned j);

int main ()
{
    int numbers[MAX_ARRAY_SIZE] = {};
    size_t size = 0;
    char element;

    std::cin >> element;

    while (element != '#')
    {
        numbers[size] = (int)element - '0';
        ++size;
        std::cin >> element;
    }

    descendingSelectionSort(numbers, size);
    printArray(numbers, size);
    
    return 0;
}

void printArray(int array[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

unsigned maxFrom(int array[], unsigned from, unsigned to)
{
    int max = from;
    for (int i = from + 1; i < to; ++i)
    {
        if (array[i] > array[max])
        {
            max = i;
        }
    }
    return max;
}

void swap(int array[], unsigned i, unsigned j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void descendingSelectionSort(int array[], size_t size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int maxIndex = maxFrom(array, i, size);
        swap(array, i, maxIndex);
    }
}