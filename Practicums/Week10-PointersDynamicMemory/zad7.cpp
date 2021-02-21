#include <iostream>

int main ()
{
    int rows;

    std::cin >> rows;

    int** numbers = new int*[rows];
    for (int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[rows-i]; // rows-i = columns
    }

    int columns = rows;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            numbers[i][j] = j+1;
        }
        --columns;
    }

    columns = rows;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            std::cout << numbers[i][j] << " ";
        }
        --columns;
    }

    for (int i = 0; i < rows; ++i)
    {
        delete[] numbers[i];
    }

    delete[] numbers;

    return 0;
}