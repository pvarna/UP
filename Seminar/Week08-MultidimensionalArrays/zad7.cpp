#include <iostream>

const int MAX_ARRAY_SIZE = 11;

void print2DArray (int arr[][MAX_ARRAY_SIZE], size_t size);

int main ()
{
    int numbers[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    
    for (int i = 0; i <= 10; ++i)
    {
        for (int j = 0; j <= 10; ++j)
        {
            numbers[i][j] = i*j;
        }
    }

    print2DArray (numbers, 11);
    return 0;
}

void print2DArray (int arr[][MAX_ARRAY_SIZE], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (arr[i][j] < 10)
            {
                std::cout << arr[i][j] << "  ";
            }
            else
            {
                std::cout << arr[i][j] << " ";
            }           
        }
        std::cout << std::endl;
    }
}