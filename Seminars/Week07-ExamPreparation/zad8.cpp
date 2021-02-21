#include <iostream>

const int MAX_SIZE_ARRAY = 1000;

size_t readSize ();

void readArray (int numbers[], size_t size);

int getMaxIncreasingPart (int numbers[], size_t size);

int main ()
{
    int numbers[MAX_SIZE_ARRAY];
    size_t size = readSize ();

    readArray (numbers, size);

    std::cout << getMaxIncreasingPart (numbers, size) << std::endl;

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

int getMaxIncreasingPart (int numbers[], size_t size)
{
    int maxIncreasingLenght = 1;
    int currentIncreasingLength = 1;

    for (int i = 1; i < size; ++i)
    {
        if (numbers[i] < numbers[i-1])
        {
            if (currentIncreasingLength > maxIncreasingLenght)
            {
                maxIncreasingLenght = currentIncreasingLength;   
            }
            currentIncreasingLength = 1;     
        }
        else
        {
            ++currentIncreasingLength;
        }      
    }
    if (currentIncreasingLength > maxIncreasingLenght)
    {
        maxIncreasingLenght = currentIncreasingLength;   
    }

    return maxIncreasingLenght;
}