#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t readSize();

void readArray(int array[], size_t size);

void printArray(int array[], size_t size);

void insertSorted(int array[], size_t size, int x);

void insertionSort(int array[], size_t size); // алгоритъм на картоиграча

int main()
{
    size_t size;
    int numbers[MAX_ARRAY_SIZE];

    size = readSize ();
    readArray(numbers, size);

    insertionSort(numbers, size);

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

void insertSorted(int array[], size_t size, int x)
{
    int i = size;
    while (i > 0 && array[i-1] > x)
    {
        array[i] = array[i-1];
        --i;
    }
    array[i] = x;
}

void insertionSort(int array[], size_t size)
{
    for (int i = 1; i < size; ++i)
    {
        insertSorted(array, i, array[i]);
    }
}