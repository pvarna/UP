#include <iostream>

const int MAX_SIZE = 100;

size_t readSize ();

void readMatrix (int array[][MAX_SIZE], size_t size);

int main ()
{
    int numbers[MAX_SIZE][MAX_SIZE];
    size_t size = readSize();

    readMatrix(numbers, size);

    int sumsRows[MAX_SIZE] = {};
    int counter = 0;

    for (int j = 0; j < size; ++j)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < size; ++i)
            {
                sumsRows[counter] += numbers[i][j];
            }
            ++counter;
        }
    }

    int totalSum = 0;

    for (int i = 0; i < counter; ++i)
    {
        std::cout << "Row " << 2*i+1 << " sum is: " << sumsRows[i] << std::endl;
        totalSum += sumsRows[i];
    }

    std::cout << "Total sum is: " << totalSum << std::endl; 
    
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