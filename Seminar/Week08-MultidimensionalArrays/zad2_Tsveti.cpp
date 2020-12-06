#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t readSize ();

void readArray (int array[], size_t size);

void printArray (int array[], size_t size);

int getCountOfConsecutiveNumbers (int array1[], int array2[], size_t size1, size_t size2);

int main ()
{
    size_t size1 = readSize (),
           size2 = readSize ();
    int array1[MAX_ARRAY_SIZE], array2[MAX_ARRAY_SIZE];

    readArray (array1, size1);
    readArray (array2, size2);

    if (size1 <= size2)
    {
        std::cout << getCountOfConsecutiveNumbers (array1, array2, size1, size2);
    }

    return 0;
}

size_t readSize ()
{
    size_t n;
    do
    {
        std::cout << "N = ";
        std::cin >> n;

    } while (n == 0 || n > MAX_ARRAY_SIZE);
    
    return n;
}

void readArray (int array[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cin >> array[i];
    }
}

void printArray (int array[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int getCountOfConsecutiveNumbers (int array1[], int array2[], size_t size1, size_t size2)
{
    int counter = 0;
    for (int i = 0; i <= size2 - size1; ++i)
    {
        int j = 0;
        while (array1[j] == array2[j+i] && (j < size1 - 1))
        {
            ++j;
        }

        if (array1[j] == array2[j+i])
        {
            ++counter;
        }
    }
    return counter;
}