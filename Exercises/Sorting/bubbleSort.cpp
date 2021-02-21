#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t readSize();

void readArray(int array[], size_t size);

void printArray(int array[], size_t size);

void swap(int array[], unsigned i, unsigned j);

void bubbleSort(int array[], size_t size); // метод на мехурчето

int main()
{
    size_t size;
    int numbers[MAX_ARRAY_SIZE];

    size = readSize ();
    readArray(numbers, size);

    bubbleSort(numbers, size);

    printArray(numbers, size);

    return 0;
}

size_t readSize()
{
    size_t n;

    do 
    {
        std::cout << "N = ";
        std::cin >> n;
    }
    while (n == 0 || n > MAX_ARRAY_SIZE);

    return n;
}

void readArray(int array[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cin >> array[i];
    }
}

void printArray(int array[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int array[], unsigned i, unsigned j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void bubbleSort(int array[], size_t size)
{
    bool changed = false;
    int sorted = 0;
    do
    {
        changed = false;
        for (int i = size-1; i > sorted; --i)
        {
            if (array[i] < array[i-1])
            {
                swap(array, i, i-1);
                changed = true;
            }
        }
        ++sorted;
    } while (changed);
    
}