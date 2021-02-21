#include <iostream>

int * createArray(int size);

void swap(int* array, int pos1, int pos2);

int minIndexFrom(int* array, int from, int to);

int * selectionSort(int* array, int size);

int main ()
{
    int size;
    
    std::cin >> size;

    int* numbers = createArray(size);

    numbers = selectionSort(numbers, size);

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

int minIndexFrom(int* array, int from, int to)
{
    int min = from;

    for (int i = from+1; i < to; ++i) {
        if (array[i] < array[min])
        {
            min = i;
        }
    }

    return min;
}

void swap(int* array, int pos1, int pos2)
{
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

int * selectionSort(int* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        swap(array, i, minIndexFrom(array, i, size));
    }

    return array;
}