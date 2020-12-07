#include <iostream>

const int MAX_ARRAY_SIZE = 10;

size_t readSize();

void readMatrix(int array[][MAX_ARRAY_SIZE], size_t size);

void swap(int array[], int pos1, int pos2);

void reverseArray(int array[], size_t size);

void printArray(int array[], size_t size);

int main ()
{
    size_t size = readSize();
    int matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    int result[MAX_ARRAY_SIZE*MAX_ARRAY_SIZE] = {};
    int countElements = 0;

    readMatrix(matrix, size);

    for (int diag = 0; diag <= (size-1)*2; ++diag)
    {
        int tempArray[MAX_ARRAY_SIZE] = {};
        int tempCount = 0;
        for (int row = 0; row < size; ++row)
        {
            int col = diag - row;
            if (col >= 0 && col <= size-1)
            {
                tempArray[tempCount] = matrix[row][col];
                ++tempCount;
            }
            /*if (row % 2 == 0)
            {
                reverseArray(tempArray, tempCount);
            }*/
        }
        //printArray(tempArray, tempCount);
        if (diag % 2 == 0)
        {
            reverseArray(tempArray, tempCount);
        }
        for (int i = 0; i < tempCount; ++i)
        {
            result[countElements] = tempArray[i];
            ++countElements;
        }
    }

    printArray(result, countElements);
    
    return 0;
}

size_t readSize()
{
    size_t n;
    do
    {
        std::cout << "N = ";
        std::cin >> n;
    } while (n < 3 || n > MAX_ARRAY_SIZE);
    
    return n;
}

void readMatrix(int array[][MAX_ARRAY_SIZE], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cin >> array[i][j];
        }
    }
}

void swap(int array[], int pos1, int pos2)
{
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

void reverseArray(int array[], size_t size)
{
    for (int i = 0; i < size/2; ++i)
    {
        swap(array, i, size-1-i);
    }
}

void printArray(int array[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}