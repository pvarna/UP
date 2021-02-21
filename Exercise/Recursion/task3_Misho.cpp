#include <iostream>

void findQuadruplet(int* array, size_t size, int wantedSum, int currentSum, int countOfCurrentElements, int currentIndex, int* quadruplet, bool& isFound);

int main ()
{
    size_t size;

    std::cin >> size;

    int* numbers = new(std::nothrow) int[size];

    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }

    int sum;
    std::cin >> sum;

    bool isFound = false;

    int* quadruplet = new(std::nothrow) int[4];

    findQuadruplet(numbers, size, sum, 0, 0, 0, quadruplet, isFound);

    if(isFound)
    {
        std::cout << "Quadruplet exists" << std::endl;
    }
    else
    {
        std::cout << "Quadruplet doesn't exist" << std::endl;
    }
    

    delete[] numbers;
    delete[] quadruplet;

    return 0;
}

void findQuadruplet(int* array, size_t size, int wantedSum, int currentSum, int countOfCurrentElements, int currentIndex, int* quadruplet, bool& isFound)
{
    if (countOfCurrentElements == 4)
    {
        if (currentSum == wantedSum)
        {
            isFound = true;
            for (int i = 0; i < 4; ++i)
            {
                std::cout << quadruplet[i] << " ";
            }
            std::cout << std::endl;
        }
        return;
    }
    if (currentIndex == size)
    {
        return;
    }

    //if (!isFound) -----> add this 'if' statement if you don't want to print all answers, but only the first that you have found
    //{
        // 2 options for the current element:
        // 1. we take it
        currentSum += array[currentIndex];
        quadruplet[countOfCurrentElements] = array[currentIndex];
        ++countOfCurrentElements;
        ++currentIndex;
        findQuadruplet(array, size, wantedSum, currentSum, countOfCurrentElements, currentIndex, quadruplet, isFound);
        --currentIndex;
        --countOfCurrentElements;
        quadruplet[countOfCurrentElements] = 0;

        currentSum -= array[currentIndex];

        // 2. we do not take it
        ++currentIndex;
        findQuadruplet(array, size, wantedSum, currentSum, countOfCurrentElements, currentIndex, quadruplet, isFound);
    //}
}