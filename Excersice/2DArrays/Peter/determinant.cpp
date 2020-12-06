#include <iostream>
#include <cmath>

const int MAX_ARRAY_SIZE = 100; 

size_t readSize ();

void readMatrix (int array[][MAX_ARRAY_SIZE], size_t size);

int calculateDeterminant (int array[][MAX_ARRAY_SIZE], size_t size);

int main ()
{
    size_t n = readSize ();
    int numbers[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

    readMatrix (numbers, n);

    std::cout << calculateDeterminant(numbers, n) << std::endl;

    return 0;
}

size_t readSize ()
{
    size_t size;
    do
    {
        std::cout << "N = ";
        std::cin >> size;

    } while (size == 0 || size > MAX_ARRAY_SIZE);
    
    return size;
}

void readMatrix (int array[][MAX_ARRAY_SIZE], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cin >> array[i][j];
        }
    }
}

int calculateDeterminant (int array[][MAX_ARRAY_SIZE], size_t size)
{
    int determinant = 0;
    if (size == 1)
    {
        return array[0][0];
    }
    if (size == 2)
    {
        return (array[0][0]*array[1][1] - array[0][1]*array[1][0]);
    }
    for (int j = 0; j < size; ++j)
    {
        int tempArray[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = {};
        int countRows = 0, countColumns = 0;
        for (int i = 1; i < size; ++i)
        {
            for (int k = 0; k < size; ++k)
            {
                if (k != j)
                {
                    tempArray[countRows][countColumns] = array[i][k];
                    ++countColumns;
                }                
            }
            ++countRows;
            countColumns = 0;
        }
        //determinant += array[0][j]*pow(-1.0, 1.0+(double)j)*calculateDeterminant(tempArray, size-1);
        if (j % 2 == 0)
        {
            determinant += array[0][j]*calculateDeterminant(tempArray, size-1);
        }
        else
        {
            determinant += array[0][j]*(-1)*calculateDeterminant(tempArray, size-1);
        }   
    }
    return determinant;   
}