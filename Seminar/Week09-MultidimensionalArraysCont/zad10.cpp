#include <iostream>

const int MAX_ROWS_SIZE = 10;
const int MAX_COLUMNS_SIZE = 20;

void read2DArray(int array[][MAX_COLUMNS_SIZE], size_t n, size_t m);

void print2DArray(int array[][MAX_COLUMNS_SIZE], size_t n, size_t m);

void removeGivenColumnFrom2DArray(int array[][MAX_COLUMNS_SIZE], size_t n, size_t m, int k);

int main ()
{
    size_t n, m;
    do
    {
        std::cin >> n >> m;
    } while (n > MAX_ROWS_SIZE || m > MAX_COLUMNS_SIZE);

    int numbers[MAX_ROWS_SIZE][MAX_COLUMNS_SIZE] = {};

    read2DArray(numbers, n, m);

    int k;
    std::cin >> k;

    removeGivenColumnFrom2DArray(numbers, n, m, k);
    --m;

    print2DArray(numbers, n, m);

    return 0;
}

void read2DArray(int array[][MAX_COLUMNS_SIZE], size_t n, size_t m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> array[i][j];
        }
    }
}

void print2DArray(int array[][MAX_COLUMNS_SIZE], size_t n, size_t m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void removeGivenColumnFrom2DArray(int array[][MAX_COLUMNS_SIZE], size_t n, size_t m, int k)
{
    for (int j = k; j < m-1; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            array[i][j] = array[i][j+1];
        }
    }
}