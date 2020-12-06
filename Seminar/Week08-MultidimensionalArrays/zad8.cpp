#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t readSize ();

void read2DArray (int arr[][MAX_ARRAY_SIZE], size_t size);

void printMD (int arr[][MAX_ARRAY_SIZE], size_t size);

void printSD (int arr[][MAX_ARRAY_SIZE], size_t size);

int main ()
{
    int numbers[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    size_t n = readSize ();

    read2DArray (numbers, n);

    std::cout << std::endl;
    printMD (numbers, n);
    printSD (numbers, n);

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

void printMD (int arr[][MAX_ARRAY_SIZE], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i][i] << " ";
    }
    std::cout << std::endl;
}

void printSD (int arr[][MAX_ARRAY_SIZE], size_t size)
{
    for (int i = size-1; i >= 0; --i)
    {
        std::cout << arr[i][size-1-i] << " ";
    }
    std::cout << std::endl;
}