#include <iostream>

const int MAX_ARRAY_SIZE = 1000;

size_t getSizeOfArray ();

void insertArrayElements (int numbers[], size_t size);

int main ()
{
    int numbers[MAX_ARRAY_SIZE] = {};
    size_t size = getSizeOfArray();
    insertArrayElements(numbers, size);

    bool flagUp = true;
    bool flagDown = true;

    for (int i = 0; i < size - 1; ++i)
    {
        if (numbers[i] > numbers[i+1] && flagUp == true)
        {
            flagUp = false;
        }
        if (numbers[i] < numbers[i+1] && flagDown == true)
        {
            flagDown = false;
        }
    }

    if (flagUp == flagDown)
    {
        std::cout << "Not increasing, not decreasing" << std::endl;
    }
    else if (flagUp)
    {
        std::cout << "Increasing " << std::endl;
    }
    else if (flagDown)
    {
        std::cout << "Decreasing " << std::endl;
    }
    

    return 0;
}

size_t getSizeOfArray()
{
    std::cout << "Insert size of array: ";
    size_t size = 0;
    std::cin >> size;
    return size;
}

void insertArrayElements (int numbers[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }
}