#include <iostream>

int* longestRowOfEqualElements(int* array, size_t size, int& maxLength);

void findLongestRow(int* array, size_t size, int& maxLenght, int& maxElement, int& currentLength, int& currentIndex);

int main ()
{
    size_t size;
    int maxLength;

    int* numbers = new(std::nothrow) int[size];

    std::cin >> size;

    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }

    int* longestRow = longestRowOfEqualElements(numbers, size, maxLength);

    for (int i = 0; i < maxLength; ++i)
    {
        std::cout << longestRow[i] << " ";
    }
    std::cout << std::endl;


    delete[] numbers;
    delete[] longestRow;

    return 0;
}

int* longestRowOfEqualElements(int* array, size_t size, int& maxLength)
{
    int maxElement = array[0], currentLength = 1, currentIndex = 1;
    maxLength = 1;

    findLongestRow(array, size, maxLength, maxElement, currentLength, currentIndex);

    int* row = new(std::nothrow) int[maxLength];
    for (int i = 0; i < maxLength; ++i)
    {
        row[i] = maxElement;
    }

    return row;
    
}

void findLongestRow(int* array, size_t size, int& maxLenght, int& maxElement, int& currentLength, int& currentIndex)
{
    if (currentIndex == size)
    {
        if (currentLength > maxLenght)
        {
            maxLenght = currentLength;
            maxElement = array[currentIndex-1];
        }
        return;
    }

    if (array[currentIndex] == array[currentIndex-1])
    {
        ++currentLength;
    }
    else
    {
        if (currentLength > maxLenght)
        {
            maxLenght = currentLength;
            maxElement = array[currentIndex-1];
        }
        currentLength = 1;
    }
    ++currentIndex;

    findLongestRow(array, size, maxLenght, maxElement, currentLength, currentIndex);
    
}
