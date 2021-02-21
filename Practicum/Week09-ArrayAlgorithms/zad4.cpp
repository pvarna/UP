#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t readSize();

void readArray(int array[], size_t size);

void printArray(int array[], size_t size);

int main ()
{
    int numbers[MAX_ARRAY_SIZE];
    size_t size = readSize();

    readArray(numbers, size);

    int maxMatches = 1;
    int element = numbers[0];
    for (int i = 0; i < size; ++i)
    {
        int currentMatches = 1;
        if (numbers[i] > 0 && numbers[i] < 5000)
        {
            for (int j = i+1; j < size; ++j)
            {
                if (numbers[i] == numbers[j])
                {
                    numbers[j] = -1;
                    ++currentMatches;
                }
            }
        }
        if (currentMatches > maxMatches)
        {
            maxMatches = currentMatches;
            element = numbers[i];
        }
    }

    std::cout << element << " - " << maxMatches << std::endl;

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