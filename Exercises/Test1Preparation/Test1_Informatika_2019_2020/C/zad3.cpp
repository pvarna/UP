#include <iostream>

const int MAX_ARRAY_SIZE = 3000;

size_t readSize ();

void readArray (int numbers[], size_t size);

void printArray (int numbers[], size_t size);

int sumOfPositiveNumbers (int numbers[], size_t size);

void removeElementOnGivenPosition (int numbers[], size_t &size, int pos);

void insertElementInArray (int numbers[], size_t &size, int number, int pos);

int main ()
{
    int numbers[MAX_ARRAY_SIZE];
    size_t size = readSize();

    readArray(numbers, size);
    printArray(numbers, size);

    int sum = sumOfPositiveNumbers(numbers, size);

    for (int i = 0; i < size; ++i)
    {
        int counter = 1;
        for (int j = i+1; j < size; ++j)
        {
            if (numbers[i] != numbers[j])
            {
                break;
            }
            ++counter;
        }
        if (counter >= 3)
        {
            for (int k = 0; k < counter; ++k)
            {
                removeElementOnGivenPosition(numbers, size, i);
            }
            insertElementInArray(numbers, size, sum, i);
        }
    }

    printArray(numbers, size);

    return 0;
}

size_t readSize ()
{
    int n;
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
int sumOfPositiveNumbers (int numbers[], size_t size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        if (numbers[i] > 0 )
        {
            sum += numbers[i];
        }
    }
    return sum;
}
void removeElementOnGivenPosition (int numbers[], size_t &size, int pos)
{
    for (int i = pos; i < size-1; ++i)
    {
        numbers[i] = numbers[i+1];
    }
    --size;
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