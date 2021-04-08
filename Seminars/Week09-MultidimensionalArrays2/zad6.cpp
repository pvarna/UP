#include <iostream>

const int MAX_ARRAY_SIZE = 10;

size_t readSize ();

void read2DArray (int arr[][MAX_ARRAY_SIZE], size_t size);

int productOfNumbersContaining1UnderSD (int arr[][MAX_ARRAY_SIZE], size_t size);

bool doesNumberContain1 (int number);

int main ()
{
    int numbers[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    size_t n = readSize ();

    read2DArray (numbers, n);

    std::cout << std::endl;

    std::cout << productOfNumbersContaining1UnderSD(numbers, n) << std::endl;
    
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

bool doesNumberContain1 (int number)
{
    while(number)
    {
        int digit = number % 10;
        if (digit == 1)
        {
            return true;
        }
        number /= 10;
    }
    return false;
}

int productOfNumbersContaining1UnderSD (int arr[][MAX_ARRAY_SIZE], size_t size)
{
    int product = 1;
    for (int i = 1; i < size; ++i)
    {
        for (int j = size-i; j < size; ++j)
        {
            if (doesNumberContain1(arr[i][j]))
            {
                product *= arr[i][j];
            }
        }
    }

    return product;
}