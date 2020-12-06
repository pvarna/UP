#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t input (double numbers[]);

double minElementOfArray (double numbers[], size_t size);

int main ()
{
    double numbers[MAX_ARRAY_SIZE] = {};
    size_t size = input(numbers);
    int counter = 0;

    double minElement = minElementOfArray (numbers, size);
    
    for (int i = 0; i < size; ++i)
    {
        if (numbers[i] == minElement)
        {
            ++counter;
        }
    }

    std::cout << counter << std::endl;

    return 0;
}

size_t input (double numbers[])
{
    size_t size;

    std::cin >> size;

    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }

    return size;
}

double minElementOfArray (double numbers[], size_t size)
{
    double minElement = numbers[0];

    for (int i = 1; i < size; ++i)
    {
        if (numbers[i] < minElement)
        {
            minElement = numbers[i];
        }
    }

    return minElement;
}