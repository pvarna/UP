#include <iostream>

bool checkIfTwoArraysArePermutation (int* array1, int* array2, size_t size);

int main ()
{
    int n, m;
    bool foundAnswer = false;

    std::cin >> n >> m;

    int ** numbers = new(std::nothrow) int*[n];
    for (int i = 0; i < n; ++i)
    {
        numbers[i] = new(std::nothrow) int[m];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> numbers[i][j];
        }
    }

    for (int j = 0; j < m; ++j)
    {
        int* array1 = new(std::nothrow) int[n];
        for (int i = 0; i < n; ++i)
        {
            array1[i] = numbers[i][j];
        }

        for (int k = j+1; k < m; ++k)
        {
            int* array2 = new(std::nothrow) int[n];
            for (int i = 0; i < n; ++i)
            {
                array2[i] = numbers[i][k];
            }
            if (checkIfTwoArraysArePermutation(array1, array2, n))
            {
                std::cout << j << " " << k << std::endl; 
                foundAnswer = true;
            }
            delete[] array2;
        }
        delete[] array1;
    }

    if (!foundAnswer)
    {
        std::cout << "No" << std::endl;
    }

    for (int i = 0; i < n; ++i)
    {
        delete[] numbers[i];
    }
    delete[] numbers;

    return 0;
}

bool checkIfTwoArraysArePermutation (int* array1, int* array2, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        bool found = false;
        for (int j = 0; j < size; ++j)
        {
            if (array1[i] == array2[j])
            {
                found = true;
                array2[j] = -1;
                break;
            }           
        }
        if (!found)
        {
            return false;
        }
    }
    return true;
}