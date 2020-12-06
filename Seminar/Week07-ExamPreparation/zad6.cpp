#include <iostream>

const int MAX_SIZE_ARRAY = 1000;

size_t readSize ();

void readArray (int numbers[], size_t size);

int getCountOfEqualPositions (int arr1[], int arr2[], size_t size1, size_t size2);

int getCountOfEqualValues (int arr1[], int arr2[], size_t size1, size_t size2);

int main ()
{
    int numbers1[MAX_SIZE_ARRAY], numbers2[MAX_SIZE_ARRAY];
    size_t size1 = readSize();
    size_t size2 = readSize();

    readArray (numbers1, size1);
    readArray (numbers2, size2);

    std::cout << getCountOfEqualPositions(numbers1, numbers2, size1, size2) << std::endl;
    std::cout << getCountOfEqualValues(numbers1, numbers2, size1, size2) << std::endl;

    return 0;
}

size_t readSize ()
{
    int n;

    do
    {
        std::cout << "N = ";
        std::cin >> n;

    } while (n <= 0 || n > MAX_SIZE_ARRAY);
    
    return n;
}

void readArray (int numbers[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }
}

int getCountOfEqualPositions (int arr1[], int arr2[], size_t size1, size_t size2)
{
    int counter = 0;
    size_t size;
    if (size1 < size2)
    {
        size = size1;
    }
    else
    {
        size = size2;
    }
    

    for (int i = 0; i < size; ++i)
    {
        if (arr1[i] == arr2[i])
        {
            ++counter;
        }
    }

    return counter;
}

int getCountOfEqualValues (int arr1[], int arr2[], size_t size1, size_t size2)
{
    int counter = 0;
    for (int i = 0; i < size1; ++i)
    {
        for (int j = 0; j < size2; ++j)
        {
            if (arr1[i] == arr2[j])
            {
                ++counter;
            }
        }
    }

    return counter;
}