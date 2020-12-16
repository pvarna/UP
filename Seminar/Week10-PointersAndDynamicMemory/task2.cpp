#include <iostream>

int ** allocateMatrix(size_t rows, size_t columns);

void clearMatrix(int ** matrix, size_t rows);

void readMatrix(int ** matrix, size_t rows, size_t columns);

void printMatrix(int ** matrix, size_t rows, size_t columns);

int * getMainDiagonal(int ** matrix, size_t rows, size_t columns);

int main ()
{
    int ** matrix = nullptr;
    size_t rows, columns;
    int * mainDiagonal = nullptr;

    std::cin >> rows >> columns;

    matrix = allocateMatrix(rows, columns);
    readMatrix(matrix, rows, columns);
    printMatrix(matrix, rows, columns);

    mainDiagonal = getMainDiagonal(matrix, rows, columns);

    for (size_t i = 0; i < rows; ++i)
    {
        std::cout << mainDiagonal[i] << " ";
    }
    std::cout << std::endl;

    delete[] mainDiagonal;
    clearMatrix(matrix, rows);

    return 0;
}

int ** allocateMatrix(size_t rows, size_t columns)
{
    int ** matrix = new(std::nothrow) int*[rows];
    if (!matrix)
    {
        return matrix;
    }

    for (size_t i = 0; i < rows; ++i)
    {
        matrix[i] = new(std::nothrow) int[columns];
        if(!matrix[i])
        {
            clearMatrix(matrix, rows);
            return nullptr;
        }
    }
    return matrix;
}

void clearMatrix(int ** matrix, size_t rows)
{
    for (size_t i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void readMatrix(int ** matrix, size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(int ** matrix, size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int * getMainDiagonal(int ** matrix, size_t rows, size_t columns)
{
    int * mainDiagonal = new(std::nothrow) int[rows];
    if(!mainDiagonal)
    {
        return mainDiagonal;
    }

    for (size_t i = 0; i < rows; ++i)
    {
        mainDiagonal[i] = matrix[i][i];
    }

    return mainDiagonal;
}