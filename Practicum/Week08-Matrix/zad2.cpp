#include <iostream>

const int MAX_SIZE = 100;

size_t readSize ();

void readMatrix (int array[][MAX_SIZE], size_t size);

bool isMatrixMagical (int array[][MAX_SIZE], size_t size);

int main ()
{
    int numbers[MAX_SIZE][MAX_SIZE];
    size_t size = readSize ();

    readMatrix (numbers, size);

    if (isMatrixMagical(numbers, size))
    {
        std::cout << "Magical" << std::endl;
    }
    else
    {
        std::cout << "Normal" << std::endl;
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

bool isMatrixMagical (int array[][MAX_SIZE], size_t size)
{
    int sumRows = 0;
    int sumColumns = 0;

    for (int i = 0; i < size; ++i)
    {
        sumColumns += array[i][0];
        sumRows += array[0][i];
    }

    if (sumColumns != sumColumns)
    {
        return false;
    }
    int sum = sumRows;

    for (int i = 0; i < size; ++i)
    {
        int sumCurrentColumn = 0;
        int sumCurrentRow = 0;
        for (int j = 0; j < size; ++j)
        {
            sumCurrentRow += array[i][j];
            sumCurrentColumn += array[j][i];
        }
        if (sumCurrentColumn != sum || sumCurrentRow != sum)
        {
            return false;
        }
    }
    return true;
}