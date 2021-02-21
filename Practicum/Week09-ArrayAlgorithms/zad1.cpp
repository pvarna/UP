#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t readSize();

void read2DArray(int array[][MAX_ARRAY_SIZE], size_t size);

void print2DArray(int array[][MAX_ARRAY_SIZE], size_t size);

void rotate2DArray(int array[][MAX_ARRAY_SIZE], size_t size);

int main ()
{
    int numbers[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    size_t size = readSize ();

    read2DArray(numbers, size);
    std::cout << std::endl;

    rotate2DArray(numbers, size);
    print2DArray(numbers, size);
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

void read2DArray(int array[][MAX_ARRAY_SIZE], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cin >> array[i][j];
        }
    }
}

void print2DArray(int array[][MAX_ARRAY_SIZE], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void rotate2DArray(int array[][MAX_ARRAY_SIZE], size_t size)
{
    int temp[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            temp[i][j] = array[j][size-1-i];
        }
    }
    
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            array[i][j] = temp[i][j];
        }
    }
}