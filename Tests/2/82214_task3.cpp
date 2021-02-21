//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в програмирането 2020/21
// Контролно 2
// 2020-01-17
//
// Начален час: 10:00 ч.
// Име: Петър Станомиров Колев
// ФН: 82214
// Специалност: Компютърни науки
// Курс: 1
// Административна група: 4
// Използван компилатор: GCC
//

#include <iostream>

int** findAnswerMatrix(int** matrix, int rows, int columns, int number, int& countOfRows, int* countOfColumnsEachRow);

int main ()
{
    int rows, columns;

    std::cin >> rows >> columns;

    int** matrix = new(std::nothrow) int*[rows];
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

    int number;
    do
    {
        std::cin >> number;
    } while (number < 1);
    

    int* countOfColumnsEachRow = new(std::nothrow) int[rows];
    int countOfRows = 0;

    int** resultMatrix = findAnswerMatrix(matrix, rows, columns, number, countOfRows, countOfColumnsEachRow);
    int currentRowAllocate = 0;
    for (int i = 0; i < rows; ++i)
    {
        if (countOfColumnsEachRow[i] != 0)
        {
            for (int j = 0; j < countOfColumnsEachRow[i]; ++j)
            {
                std::cout << resultMatrix[currentRowAllocate][j] << " ";
            }
            std::cout << std::endl;
            ++currentRowAllocate;
        }
    }


    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] countOfColumnsEachRow;
    for (int i = 0; i < countOfRows; ++i)
    {
        delete[] resultMatrix[i];
    }
    delete[] resultMatrix;

    return 0;
}

int** findAnswerMatrix(int** matrix, int rows, int columns, int number, int& countOfRows, int* countOfColumnsEachRow)
{
    countOfRows = 0;
    for (int i = 0; i < rows; ++i)
    {
        countOfColumnsEachRow[i] = 0;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (matrix[i][j] % number == 0)
            {
                ++countOfColumnsEachRow[i];
            }
        }
        if (countOfColumnsEachRow[i] > 0)
        {
            ++countOfRows;
        }
    }

    /*std::cout << countOfRows << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        std::cout << countOfColumnsEachRow[i] << " ";
    }
    std::cout << std::endl;*/

    int** resultMatrix = new(std::nothrow) int*[countOfRows];
    int currentRowAllocate = 0;
    for (int i = 0; i < rows; ++i)
    {
        if (countOfColumnsEachRow[i] != 0)
        {
            for (int j = 0; j < countOfColumnsEachRow[i]; ++j)
            {
                resultMatrix[currentRowAllocate] = new(std::nothrow) int[countOfColumnsEachRow[i]];
            }
            ++currentRowAllocate;
        }
    }

    int currentRow = 0, currentColumn = 0;
    for (int i = 0; i < rows; ++i)
    {
        currentColumn = 0;
        if (countOfColumnsEachRow[i] != 0)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (currentColumn == countOfColumnsEachRow[i])
                {
                    break;
                }
                if (matrix[i][j] % number == 0)
                {
                    resultMatrix[currentRow][currentColumn] = matrix[i][j];
                    ++currentColumn;
                }
            }
            ++currentRow;
        }
    }

    return resultMatrix;
}