#include <iostream>

const int MAX_ARRAY_SIZE = 1000;

size_t readSize();

void readArray (int numbers[], size_t size);

void printArray (int numbers[], size_t size);

double averageOfElementsOfArray (int numbers[], size_t size);

void removeElementOnGivenPosition (int numbers[], size_t &size, int pos);

int main ()
{
    int numbers[MAX_ARRAY_SIZE];
    size_t size = readSize();
    
    readArray (numbers, size);
    printArray (numbers, size);
    //std::cout << std::endl;

    double average = averageOfElementsOfArray(numbers, size);
    for (int i = 0; i < size; ++i)
    {
        if ((double)numbers[i] < average)
        {
            removeElementOnGivenPosition(numbers, size, i);
            //printArray(numbers, size);
            //std::cout << std::endl;
            --i;
        }
    }
    std::cout << std::endl;
    printArray(numbers, size);

    return 0;
}

size_t readSize()
{
    size_t n;

    do {
        std::cout << "N = ";
        std::cin >> n;
    } while (n == 0 || n > MAX_ARRAY_SIZE);

    return n;
}

void readArray (int numbers[], size_t size)
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
}

double averageOfElementsOfArray (int numbers[], size_t size)
{
    double sum = 0.0;

    for (int i = 0; i < size; ++i)
    {
        sum += numbers[i];
    }

    return (sum / (double)size);
}

void removeElementOnGivenPosition (int numbers[], size_t &size, int pos)
{
    for (int i = pos; i < size-1; ++i)
    {
        numbers[i] = numbers[i+1];
    }
    --size;
}