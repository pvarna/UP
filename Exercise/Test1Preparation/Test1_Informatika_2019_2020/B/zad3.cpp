#include <iostream>

const int MAX_ARRAY_SIZE = 5000;

size_t readSize ();

void readArray (int numbers[], size_t size);

void printArray (int numbers[], size_t size);

int sumOfOddNumbersSmallerThanGivenNumber (int numbers[], size_t size, int number);

void insertElementInArray (int numbers[], size_t &size, int number, int pos);

int main ()
{
    int numbers[MAX_ARRAY_SIZE];
    size_t size = readSize();

    readArray (numbers, size);
    printArray (numbers, size);

    int initialArray[MAX_ARRAY_SIZE];
    int initialSize = size;
    for (int i = 0; i < size; ++i)
    {
        initialArray[i] = numbers[i];
    }

    for (int i = 0; i < size; ++i)
    {
        if (numbers[i] % 2 == 0)
        {
            insertElementInArray(numbers, size, numbers[i]/2, i+1);
            ++i;
        }
        else
        {
            insertElementInArray(numbers, size, sumOfOddNumbersSmallerThanGivenNumber(initialArray, initialSize, numbers[i]), i+1);
            ++i;
        }
    }
    printArray(numbers, size);

    return 0;
}

size_t readSize ()
{
    size_t n;
    do
    {
        std::cout << "N = ";
        std::cin >> n;
    } while (n <= 0 || n > MAX_ARRAY_SIZE);
    
    return n;
}

void readArray (int numbers[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }
}

void printArray (int numbers[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

int sumOfOddNumbersSmallerThanGivenNumber (int numbers[], size_t size, int number)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        if (numbers[i] < number && numbers[i] % 2 == 1)
        {
            sum += numbers[i];
        }
    }

    return sum;
}

void insertElementInArray (int numbers[], size_t &size, int number, int pos)
{
    ++size;
    for (int i = size-1; i > pos; --i)
    {
        numbers[i] = numbers[i-1]; 
    }
    numbers[pos] = number;
}