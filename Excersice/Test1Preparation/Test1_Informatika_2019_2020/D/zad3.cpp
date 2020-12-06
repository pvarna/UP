#include <iostream>
#include <cmath>

const int MAX_ARRAY_SIZE = 500;

size_t readSize ();

void readArray (int numbers[], size_t size);

void printArray (int numbers[], size_t size);

void removeElementOnGivenPosition (int numbers[], size_t &size, int pos);

void insertGivenElementInArray (int numbers[], size_t &size, int pos, int number);

int main ()
{
    int numbers[MAX_ARRAY_SIZE];
    size_t size = readSize ();

    readArray (numbers, size);
    printArray (numbers, size);

    for (int i = 0; i < size-1; ++i)
    {
        if (numbers[i] < numbers[i+1])
        {
            double average = floor(((double)numbers[i]+(double)numbers[i+1])/2.0);
            insertGivenElementInArray(numbers, size, i+1, average);
            ++i;
        }
    }

    printArray (numbers, size);
    return 0;
}

size_t readSize ()
{
    int n;
    do
    {
        std::cout << "N = ";
        std::cin >> n;

    } while (n <= 0 || n > MAX_ARRAY_SIZE);

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
    std::cout << std::endl;
}

void removeElementOnGivenPosition (int numbers[], size_t &size, int pos)
{
    for (int i = pos; i < size-1; ++i)
    {
        numbers[i] = numbers[i+1];
    }
    --size;
}

void insertGivenElementInArray (int numbers[], size_t &size, int pos, int number)
{
    ++size;
    for (int i = size-1; i > pos; --i)
    {
        numbers[i] = numbers[i-1];
    }
    numbers[pos] = number;
}