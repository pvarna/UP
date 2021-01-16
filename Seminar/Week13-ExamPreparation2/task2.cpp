#include <iostream>

int** insertMatrix(int rows, int columns);

void deleteMemory(int** array, size_t rows);

int** multiplyMatrices(int** matrix1, int rows1, int columns1, int** matrix2, int rows2, int columns2);

int main ()
{
    int rows1, columns1, rows2, columns2;

    std::cin >> rows1 >> columns1;
    int** matrix1 = insertMatrix(rows1, columns1);

    std::cin >> rows2 >> columns2;
    int** matrix2 = insertMatrix(rows2, columns2);

    int** matrix = multiplyMatrices(matrix1, rows1, columns1, matrix2, rows2, columns2);

    for (int i = 0; i < columns1; ++i)
    {
        for (int j = 0; j < rows2; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    deleteMemory(matrix1, rows1);
    deleteMemory(matrix2, rows2);
    deleteMemory(matrix, rows1);

    return 0;
}

int** insertMatrix(int rows, int columns)
{
    int ** matrix = new(std::nothrow) int*[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new(std::nothrow) int[columns];
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    return matrix;
}

void deleteMemory(int** array, size_t rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
}

int** multiplyMatrices(int** matrix1, int rows1, int columns1, int** matrix2, int rows2, int columns2)
{
    if (columns1 != rows2)
    {
        return nullptr;
    }

    int ** matrix = new(std::nothrow) int*[rows1];
    for (int i = 0; i < rows1; ++i)
    {
        matrix[i] = new(std::nothrow) int[columns2];
    }

    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < columns2; ++j)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < columns2; ++j)
        {
            for (int k = 0; k < columns1; ++k)
            {
                matrix[i][j] += (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }

    return matrix;
}