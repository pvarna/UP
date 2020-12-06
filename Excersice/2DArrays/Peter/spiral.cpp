#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t readSize ();

void read2DArray (int array[][MAX_ARRAY_SIZE], size_t n, size_t m);

void printArray (int array[], size_t n);

void print2DArray (int array[][MAX_ARRAY_SIZE], size_t n, size_t m);

int main ()
{
    int numbers[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], result[MAX_ARRAY_SIZE*MAX_ARRAY_SIZE];
    size_t n = readSize ();
    size_t m = readSize ();

    read2DArray (numbers, n, m);

    std::cout << std::endl;

    print2DArray (numbers, n, m);

    int counter = 0;
    int left = 0, down = n, right = m, up = 0;

    while (counter < m*n)
    {
        for (int i = left; i < right; ++i)
        {
            result[counter] = numbers[up][i];
            ++counter;
        }
        ++up;

        for (int i = up; i < down; ++i)
        {
            result[counter] = numbers[i][right-1];
            ++counter;
        }
        --right;

        for (int i = right-1; i >= left; --i)
        {
            result[counter] = numbers[down-1][i];
            ++counter;
        }
        --down;
        
        for (int i = down-1; i >= up; --i)
        {
            result[counter] = numbers[i][left];
            ++counter;
        }
        ++left;
    }

    printArray (result, m*n);

    return 0;
}

size_t readSize ()
{
    size_t size;
    do
    {
        std::cout << "N = ";
        std::cin >> size;

    } while (size <= 0 || size > MAX_ARRAY_SIZE);
    
    return size;
}

void read2DArray (int array[][MAX_ARRAY_SIZE], size_t n, size_t m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> array[i][j];
        }
    }
}

void printArray (int array[], size_t n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void print2DArray (int array[][MAX_ARRAY_SIZE], size_t n, size_t m)
{
    for (int i = 0; i < n; ++i)
    {
        printArray(array[i], m);
    }
    std::cout << std::endl;
}