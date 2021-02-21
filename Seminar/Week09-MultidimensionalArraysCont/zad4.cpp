#include <iostream>

const int MAX_ARRAY_SIZE = 10;

size_t readSize ();

void read2DArray (int arr[][MAX_ARRAY_SIZE], size_t size);

int sumOfOddNumbersOverMD (int arr[][MAX_ARRAY_SIZE], size_t size);

int main ()
{
    int numbers[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    size_t n = readSize ();

    read2DArray (numbers, n);

    std::cout << std::endl;

    std::cout << sumOfOddNumbersOverMD(numbers, n) << std::endl;
    
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

int sumOfOddNumbersOverMD (int arr[][MAX_ARRAY_SIZE], size_t size)
{
    int sum = 0;
    for (int i = 0; i < size-1; ++i)
    {
        for (int j = i+1; j < size; ++j)
        {
            if (arr[i][j] % 2 == 1)
            {
                sum += arr[i][j];
            }
        }
    }

    return sum;
}