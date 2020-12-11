#include <iostream>

int * createArray(int size);

void sumMinMax(int* array, int size, int* min, int* max, int* sum);

int main ()
{
    int size, sum;
    int min, max;

    std::cin >> size;

    int* myArray = createArray(size);

    sumMinMax(myArray, size, &min, &max, &sum);

    std::cout << min << " " << max << " " << sum << std::endl; 

    delete myArray;

    return 0;
}

int * createArray(int size)
{
    int* array = new int[size];

    for (int i = 0; i < size; ++i)
    {
        std::cin >> *(array + i);
    }

    return array;
}

void sumMinMax(int* array, int size, int* min, int* max, int* sum)
{
    *min = array[0];
    *max = array[0];
    *sum = 0;
    for (int i = 0; i < size; ++i)
    {
        if (array[i] < *min)
        {
            *min = array[i];
        }
        if (array[i] > *max)
        {
            *max = array[i];
        }
        *sum += array[i];
    }
}