#include <iostream>

int find_sum(int* array, int size);

int main ()
{
    size_t size;

    std::cin >> size;

    int* myArray = new int[size];

    for (int i = 0; i < size; ++i)
    {
        std::cin >> *(myArray + i);
    }
    std::cout << find_sum(myArray, size) << std::endl;

    return 0;
}

int find_sum(int* array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += *(array + i);
    }
    delete array;
    return sum;
}