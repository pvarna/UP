#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t readSize();

void readArray(int* array, size_t size);

void printArray(const int* array, size_t size);

const int* minElement(const int* array, size_t size);

void swap(int* a, int* b);

void selectionSort(int* array, size_t size);

int main ()
{
    size_t n = readSize();
    int numbers[MAX_ARRAY_SIZE];
    int min, max;

    readArray(numbers, n);
    //std::cout << std::endl;
    printArray(numbers, n);

    selectionSort(numbers, n);
    printArray(numbers, n);

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

const int* minElement(const int* array, size_t size)
{
    const int* min = array;
    for (int i = 1; i < size; ++i)
    {
        if (array[i] < *min)
        {
            min = array +i;
        }
    }
    return min;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int* array, size_t size)
{
    for (size_t i = 0; i < size-1; ++i)
    {
        swap(array+i, array+(minElement(array+i, size-i)-array));
    }
}