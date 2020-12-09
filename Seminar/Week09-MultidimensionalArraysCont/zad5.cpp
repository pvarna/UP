#include <iostream>

const int MAX_ARRAY_SIZE = 10;

size_t readSize ();

void read2DArray (int arr[][MAX_ARRAY_SIZE], size_t size);

int numberOfPrimeNumbersOverSD (int arr[][MAX_ARRAY_SIZE], size_t size);

bool isNumberPrime (int number);

int main ()
{
    int numbers[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    size_t n = readSize ();

    read2DArray (numbers, n);

    std::cout << std::endl;

    std::cout << numberOfPrimeNumbersOverSD(numbers, n) << std::endl;
    
    return 0;
}

size_t readSize ()
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

void read2DArray (int arr[][MAX_ARRAY_SIZE], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cin >> arr[i][j];
        }
    }
}

bool isNumberPrime (int number)
{
    int counter = 0;
    for (int i = 2; i <= number/2; ++i)
    {
        if (number % i == 0)
        {
            ++counter;
        }
    }

    if(counter > 0)
    {
        return false;
    }
    return true;
}

int numberOfPrimeNumbersOverSD (int arr[][MAX_ARRAY_SIZE], size_t size)
{
    int counter = 0;
    for (int i = 0; i < size-1; ++i)
    {
        for (int j = 0; j < size-1-i; ++j)
        {
            if (isNumberPrime(arr[i][j]))
            {
                ++counter;
            }
        }
    }

    return counter;
}