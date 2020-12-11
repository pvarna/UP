#include <iostream>

int * createArray(int size);

void swap(int* array, int pos1, int pos2);

int main ()
{
    int size;
    
    std::cin >> size;

    int* numbers = createArray(size);

    for (int i = 0; i < size/2; ++i)
    {
        if (numbers[i] > numbers[size-1-i])
        {
            swap(numbers, i, size-1-i);
        }
    }

    for (int i = 0; i < size; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    delete[] numbers;

    return 0;
}

int * createArray(int size)
{
    int* array = new int[size];

    for (int i = 0; i < size; ++i)
    {
        std::cin >> array[i];
    }

    return array;
}

void swap(int* array, int pos1, int pos2)
{
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}