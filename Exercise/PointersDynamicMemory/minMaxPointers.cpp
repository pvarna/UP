#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t readSize();

void readArray(int* array, size_t size);

void printArray(const int* array, size_t size);

void minMaxPtr(int* array, size_t size, int** min, int** max);

void minMax(int* array, size_t size, int* min, int* max);

int main ()
{
    size_t n = readSize();
    int numbers[MAX_ARRAY_SIZE];
    int min, max;

    readArray(numbers, n);
    //std::cout << std::endl;
    printArray(numbers, n);

    minMax(numbers, n, &min, &max);

    std::cout << min << " " << max << std::endl;

    return 0;
}

size_t readSize()
{
    size_t n;
    do
    {
        std::cout << "N = ";
        std::cin >> n;
    } while (n == 0 || n > MAX_ARRAY_SIZE);
    
    return n;
}

void readArray(int* array, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cin >> array[i];
    }
}

void printArray(const int* array, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void minMaxPtr(int* array, size_t size, int** min, int** max)
{
    *min = array;
    *max = array;

    for (int* end = array+size; array < end; ++array)
    {
        if (*array < **min)
        {
            *min = array;
        }
        if (*array > **max)
        {
            *max = array;
        }
    } 
}

void minMax(int* array, size_t size, int* min, int* max)
{
    int *minPtr, *maxPtr;

    minMaxPtr(array, size, &minPtr, &maxPtr);

    *min = *minPtr;
    *max = *maxPtr;
}