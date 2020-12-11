#include <iostream>

int * createArray(int size);

int main ()
{
    int size;

    std::cin >> size;

    int* myArray = createArray(size);
    
    for (int i = 0; i < size; ++i)
    {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    delete myArray;

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