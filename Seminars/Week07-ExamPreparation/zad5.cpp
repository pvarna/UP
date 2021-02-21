#include <iostream>

const int MAX_SIZE_ARRAY = 1000;

size_t readSize ();

void readArray (int numbers[], size_t size);

int sumOfEvenNumbers (int numbers[], size_t size);

int main ()
{
    int numbers[MAX_SIZE_ARRAY];
    size_t size = readSize();

    readArray(numbers, size);

    std::cout << sumOfEvenNumbers(numbers, size) << std::endl;

    return 0;
}

size_t readSize ()
{
    int n;

    do
    {
        std::cout << "N = ";
        std::cin >> n;

    } while (n <= 0 || n > MAX_SIZE_ARRAY);
    
    return n;
}

void readArray (int numbers[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }
}

int sumOfEvenNumbers (int numbers[], size_t size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        if (numbers[i] % 2 == 0)
        {
            sum += numbers[i];
        }
    }

    return sum;
}