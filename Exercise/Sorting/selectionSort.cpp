#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t readSize();

void readArray(int array[], size_t size);

void printArray(int array[], size_t size);

unsigned minFrom(int array[], unsigned from, unsigned to); // returns the index

void swap(int array[], unsigned i, unsigned j);

void selectionSort(int array[], size_t size); // метод на пряката селекция

int main()
{
    size_t size;
    int numbers[MAX_ARRAY_SIZE];

    size = readSize ();
    readArray(numbers, size);

    selectionSort(numbers, size);

    printArray(numbers, size);

    return 0;
}

size_t readSize()
{
    size_t n;

    do 
    {
        std::cout << "N = ";
        std::cin >> n;
    }
    while (n == 0 || n > MAX_ARRAY_SIZE);

    return n;
}

void readArray(int array[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cin >> array[i];
    }
}

void printArray(int array[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

unsigned minFrom(int array[], unsigned from, unsigned to)
{
    int min = from;
    for (int i = from + 1; i < to; ++i)
    {
        if (array[i] < array[min])
        {
            min = i;
        }
    }
    return min;
}

void selectionSort(int array[], size_t size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = minFrom(array, i, size);
        swap(array, i, minIndex);
    }
    
}

void swap(int array[], unsigned i, unsigned j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}