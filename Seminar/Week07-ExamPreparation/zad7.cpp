#include <iostream>

const int MAX_SIZE_ARRAY = 1000;

size_t readSize ();

void readArray (int numbers[], size_t size);

bool isArraySorted (int numbers[], size_t size);

int main ()
{
    int numbers[MAX_SIZE_ARRAY];
    size_t size = readSize();

    readArray (numbers, size);

    if (isArraySorted(numbers, size))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    
    return 0;
}

size_t readSize ()
{
    int n;

    do
    {
        std::cout << "N = ";
        std::cin >> n;

    } while (n <= 0 || n > MAX_SIZE_ARRAY);
    
    return n;
}

void readArray (int numbers[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }
}

bool isArraySorted (int numbers[], size_t size)
{
    for (int i = 0; i < size-1; ++i)
    {
        if (numbers[i] > numbers[i+1])
        {
            return false;
        }
    }
    return true;
}