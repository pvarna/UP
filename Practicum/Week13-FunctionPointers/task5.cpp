#include <iostream>

typedef bool (*mainFunc) (int x, int y);

bool ascending(int x, int y)
{
    return x > y;
}

bool descending(int x, int y)
{
    return x < y;
}

void swap(int* array, unsigned i, unsigned j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void sort(mainFunc fn, int* array, size_t size)
{
    bool changed = false;
    int sorted = 0;
    do
    {
        changed = false;
        for (int i = size-1; i > sorted; --i)
        {
            if (fn(array[i], array[i-1]))
            {
                swap(array, i, i-1);
                changed = true;
            }
        }
        ++sorted;
    } while (changed);
    
}

int main ()
{
    size_t size;

    std::cin >> size;

    int* numbers = new(std::nothrow) int[size];

    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }

    sort(ascending, numbers, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    sort(descending, numbers, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    delete[] numbers;
    return 0;
}