#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t input (int numbers[]);

void removeElementOnGivenPosition (int numbers[], size_t &size, int pos);

int main ()
{
    int numbers[MAX_ARRAY_SIZE] = {};
    size_t size = input(numbers);
    int maxTimes = 1, numberMaxTimes = numbers[0];

    for (int i = 0; i < size; ++i)
    {
        int counter = 1;
        for (int j = i + 1; j < size; ++j)
        {
            if (numbers[j] == numbers[i])
            {
                ++counter;
                removeElementOnGivenPosition(numbers, size, j);
                --j;
            }
        }
        if (counter > maxTimes)
        {
            maxTimes = counter;
            numberMaxTimes = numbers[i];
        }
    }

    std::cout << numberMaxTimes << std::endl;
    std::cout << maxTimes << " times" << std::endl;

    return 0;
}

size_t input (int numbers[])
{
    size_t size;

    std::cin >> size;

    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }

    return size;
}

void removeElementOnGivenPosition (int numbers[], size_t &size, int pos)
{
    for (int i = pos; i < size - 1; ++i)
    {
        numbers[i] = numbers[i+1]; 
    }
    --size;
}