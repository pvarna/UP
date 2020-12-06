#include <iostream>

const int MAX_SIZE = 100;

size_t readSize ();

void readMatrix (int array[][MAX_SIZE], size_t size);

void transposeMatrix (int array[][MAX_SIZE], size_t size);

void printMatrix (int array[][MAX_SIZE], size_t size);

int main ()
{
    int numbers[MAX_SIZE][MAX_SIZE];
    size_t size = readSize ();

    readMatrix (numbers, size);
    transposeMatrix (numbers, size);
    printMatrix (numbers, size);

    return 0;
}

size_t readSize ()
{
    int n;
    do
    {
        std::cout << "N = ";
        std::cin >> n;

    } while (n <= 0 || n > MAX_SIZE);
    
    return n;
}

void readMatrix (int array[][MAX_SIZE], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cin >> array[i][j];
        }
    }
}

void transposeMatrix (int array[][MAX_SIZE], size_t size)
{
    int temp[MAX_SIZE][MAX_SIZE] = {};

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            temp[i][j] = array[i][j];
        }
    }
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            array[i][j] = temp[j][i];
        }
    }
}

void printMatrix (int array[][MAX_SIZE], size_t size)
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