#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t readSize();

void readArray(int array[], size_t size);

void printArray(int array[], size_t size);

void removeElementOnGivenPosition(int array[], size_t size, unsigned pos);

int main ()
{
    int numbers[MAX_ARRAY_SIZE];
    size_t size = readSize();
    unsigned k;

    readArray(numbers, size);
    std::cin >> k;

    removeElementOnGivenPosition(numbers, size, k);

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

void removeElementOnGivenPosition(int array[], size_t size, unsigned pos)
{
    for (int i = pos; i < size - 1; ++i)
    {
        array[i] = array[i+1];
    }
    array[size-1] = -1;
}