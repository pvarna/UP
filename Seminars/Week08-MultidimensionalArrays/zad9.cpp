#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t readSize ();

void read2DArray (int arr[][MAX_ARRAY_SIZE], size_t size);

void printElementsUnderMD (int arr[][MAX_ARRAY_SIZE], size_t size);

void printElementsOverMD (int arr[][MAX_ARRAY_SIZE], size_t size);

void printElementsUnderSD (int arr[][MAX_ARRAY_SIZE], size_t size);

void printElementsOverSD (int arr[][MAX_ARRAY_SIZE], size_t size);

int main ()
{
    int numbers[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    size_t n = readSize ();

    read2DArray (numbers, n);

    std::cout << std::endl;

    std::cout << "Elements under the main diagonal: ";
    printElementsUnderMD (numbers, n);
    std::cout << "Elements over the main diagonal: ";
    printElementsOverMD (numbers, n);
    std::cout << "Elements under the secondary diagonal: ";
    printElementsUnderSD (numbers, n);
    std::cout << "Elements over the secondary diagonal: ";
    printElementsOverSD (numbers, n);



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

void printElementsUnderMD (int arr[][MAX_ARRAY_SIZE], size_t size)
{
    for (int i = 1; i < size; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
    }
    std::cout << std::endl;
}

void printElementsOverMD (int arr[][MAX_ARRAY_SIZE], size_t size)
{
    for (int i = 0; i < size-1; ++i)
    {
        for (int j = i+1; j < size; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
    }
    std::cout << std::endl;
}

void printElementsUnderSD (int arr[][MAX_ARRAY_SIZE], size_t size)
{
    for (int i = 1; i < size; ++i)
    {
        for (int j = size-i; j < size; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
    }
    std::cout << std::endl;
}

void printElementsOverSD (int arr[][MAX_ARRAY_SIZE], size_t size)
{
    for (int i = 0; i < size-1; ++i)
    {
        for (int j = 0; j < size-1-i; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
    }
    std::cout << std::endl;
}