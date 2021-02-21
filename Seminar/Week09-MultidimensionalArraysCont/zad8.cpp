#include <iostream>

const int MAX_ARRAY_SIZE = 10;

size_t readSize ();

void read2DArray (int arr[][MAX_ARRAY_SIZE], size_t size);

int getIndexOfRowWithBiggestSum (int arr[][MAX_ARRAY_SIZE], size_t size);

int getIndexOfColumnWithBiggestSum (int arr[][MAX_ARRAY_SIZE], size_t size);

int main ()
{
    int numbers[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    size_t n = readSize ();

    read2DArray (numbers, n);

    int indexRow = getIndexOfRowWithBiggestSum(numbers, n);
    int indexColumn = getIndexOfColumnWithBiggestSum(numbers, n);

    std::cout << std::endl;

    std::cout << "Row with biggest sum of elements: " << std::endl;
    for (int j = 0; j < n; ++j)
    {
        std::cout << numbers[indexRow][j] << " ";
    }
    std::cout << std::endl;

    std::cout << "Column with biggest sum of elements: " << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << numbers[i][indexColumn] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

size_t readSize ()
{
    size_t n;
    do
    {
        std::cout << "N = ";
        std::cin >> n;
    }
    while (n == 0 || n > MAX_ARRAY_SIZE);

    return n;
}

void read2DArray (int arr[][MAX_ARRAY_SIZE], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cin >> arr[i][j];
        }
    }
}

int getIndexOfRowWithBiggestSum (int arr[][MAX_ARRAY_SIZE], size_t size)
{
    int maxIndex = 0, maxSum = 0;
    for (int i = 0; i < size; ++i)
    {
        maxSum += arr[0][i];
    }

    for (int i = 0; i < size; ++i)
    {
        int currentSum = 0;
        for (int j = 0; j < size; ++j)
        {
            currentSum += arr[i][j];
        }
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            maxIndex = i;
        }
    }

    return maxIndex;
}

int getIndexOfColumnWithBiggestSum (int arr[][MAX_ARRAY_SIZE], size_t size)
{
    int maxIndex = 0, maxSum = 0;
    for (int j = 0; j < size; ++j)
    {
        maxSum += arr[j][0];
    }

    for (int j = 0; j < size; ++j)
    {
        int currentSum = 0;
        for (int i = 0; i < size; ++i)
        {
            currentSum += arr[i][j];
        }
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            maxIndex = j;
        }
    }

    return maxIndex;
}