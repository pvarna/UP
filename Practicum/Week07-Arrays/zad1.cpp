#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t getSizeOfArray ();

void insertArrayElements (int numbers[], size_t size);

int minElementOfArray (int numbers[], size_t size);

int maxElementOfArray (int numbers[], size_t size);

int sumOfElementsOfArray (int numbers[], size_t size);

int productOfElementsOfArray (int numbers[], size_t size);

double averageOfElementsOfArray (int numbers[], size_t size);

int main ()
{
    int numbers[MAX_ARRAY_SIZE] = {};
    size_t size;

    size = getSizeOfArray ();
    insertArrayElements (numbers, size);

    std::cout << "min: " << minElementOfArray (numbers, size) << std::endl;
    std::cout << "max: " << maxElementOfArray (numbers, size) << std::endl;
    std::cout << "sum: " << sumOfElementsOfArray (numbers, size) << std::endl; 
    std::cout << "multiply: " << productOfElementsOfArray (numbers, size) << std::endl;
    std::cout << "average: " << averageOfElementsOfArray (numbers, size) << std::endl;

    return 0;
}

size_t getSizeOfArray ()
{
    size_t size;

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

int minElementOfArray (int numbers[], size_t size)
{
    int minElement = numbers[0];

    for (int i = 1; i < size; ++i)
    {
        if (numbers[i] < minElement)
        {
            minElement = numbers[i];
        }
    }

    return minElement;
}

int maxElementOfArray (int numbers[], size_t size)
{
    int maxElement = numbers[0];

    for (int i = 1; i < size; ++i)
    {
        if (numbers[i] > maxElement)
        {
            maxElement = numbers[i];
        }
    }

    return maxElement;
}

int sumOfElementsOfArray (int numbers[], size_t size)
{
    int sum = 0;

    for (int i = 0; i < size; ++i)
    {
        sum += numbers[i];
    }

    return sum;
}

int productOfElementsOfArray (int numbers[], size_t size)
{
    int product = 1;

    for (int i = 0; i < size; ++i)
    {
        product *= numbers[i];
    }

    return product;
}

double averageOfElementsOfArray (int numbers[], size_t size)
{
    return ((double)sumOfElementsOfArray (numbers, size) / (double)size);
}