#include <iostream>

int ** allocateMatrix(size_t rows, size_t columns);

void clearMatrix(int ** matrix, size_t rows);

void readMatrix(int ** matrix, size_t rows, size_t columns);

void printMatrix(int ** matrix, size_t rows, size_t columns);

int ** getFirstNRowsAndMColumns(int ** matrix, size_t rows, size_t columns, int n, int m);

int main ()
{
    int ** matrix = nullptr;
    size_t rows, columns;
    int * mainDiagonal = nullptr;
    int n, m;

    std::cout << "Enter the size of the matrix: " << std::endl;
    std::cin >> rows >> columns;
    
    std::cout << "N = ";
    std::cin >> n;
    std::cout << "M = ";
    std::cin >> m;

    matrix = allocateMatrix(rows, columns);
    readMatrix(matrix, rows, columns);
    int ** result = getFirstNRowsAndMColumns(matrix, rows, columns, n, m);

    printMatrix(result, n, m);

    clearMatrix(matrix, rows);
    clearMatrix(result, n);

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

int ** getFirstNRowsAndMColumns(int ** matrix, size_t rows, size_t columns, int n, int m)
{
    int ** result = allocateMatrix(n, m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            result[i][j] = matrix[i][j];
        }
    }
    return result;
}