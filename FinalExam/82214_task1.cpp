//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Практически изпит - задачи
// 2021-02-08
//
// Име: Петър Станомиров Колев
// ФН: 82214
// Специалност: Компютърни науки, 1 поток
// Курс: 1
// Административна група: 4
// Използван компилатор: GCC
//

#include <iostream>

bool areNumbersFriendly(int number1, int number2);

bool isNumberOddPrime(int number);

bool removeFriendlyNumbers(int* numbers, size_t& n);

void removeAt(int* numbers, size_t n, int index);

int searchMinSum(int* numbers, size_t n, int currentNumber, int* indexes, size_t countIndexes);

int main ()
{
    size_t n;

    std::cin >> n;

    int* numbers = new(std::nothrow) int[n];
    if (!numbers)
    {
        delete[] numbers;
        std::cout << "Memory problem!" << std::endl;
        return 1;
    }

    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    if (!removeFriendlyNumbers(numbers, n))
    {
        delete[] numbers;
        return 1;
    }
    else
    {
        for (size_t i = 0; i < n; ++i)
        {
            std::cout << numbers[i] << " ";;
        }
        std::cout << std::endl;
    }

    delete[] numbers;

    return 0;
}

bool isNumberOddPrime(int number)
{
    if (number == 1)
    {
        return false;
    }

    if (number % 2 == 0)
    {
        return false;
    }

    for (int i = 3; i < number/2; ++i)
    {
        if (number % 2 == 0)
        {
            return false;
        }
    }

    return true;
}

bool areNumbersFriendly(int number1, int number2)
{
    int temp1 = number1, temp2 = number2;
    int counter = 0;

    while (temp1 && temp2)
    {
        if ((temp1 & 1) != (temp2 & 1))
        {
            ++counter;
        }
        temp1 = (temp1 >> 1);
        temp2 = (temp2 >> 1);
    }

    if (temp1)
    {
        while (temp1)
        {
            if (temp1 & 1)
            {
                ++counter;
            }
            temp1 = (temp1 >> 1);
        }
    }

    if (temp2)
    {
        while (temp2)
        {
            if (temp2 & 1)
            {
                ++counter;
            }
            temp2 = (temp2 >> 1);
        }
    }

    //std::cout << counter << std::endl;

    return isNumberOddPrime(counter);
}

bool removeFriendlyNumbers(int* numbers, size_t& n)
{
    for (size_t i = 0; i < n-1; ++i)
    {
        int* indexesFriendlyNumbers = new(std::nothrow) int[n];
        int countOfIndexes = 0;

        if (!indexesFriendlyNumbers)
        {
            std::cout << "Memory problem!" << std::endl;
            delete[] indexesFriendlyNumbers;
            return false;
        }

        for (size_t j = i+1; j < n; ++j)
        {
            if (areNumbersFriendly(numbers[i], numbers[j]))
            {
                indexesFriendlyNumbers[countOfIndexes] = j;
                ++countOfIndexes;
            }
        }

        if (countOfIndexes == 1)
        {
            removeAt(numbers, n, indexesFriendlyNumbers[0]);
            --n;
            removeAt(numbers, n, i);
            --i;
            --n;
        }

        else if (countOfIndexes > 1)
        {
            int minIndex = searchMinSum(numbers, n, numbers[i], indexesFriendlyNumbers, countOfIndexes);
            removeAt(numbers, n, minIndex);
            --n;
            removeAt(numbers, n, i);
            --i;
            --n;
        }
    }

    return true;
}

void removeAt(int* numbers, size_t n, int index)
{
    for (int i = index; i < n-1; ++i)
    {
        numbers[i] = numbers[i+1];
    }
}

int searchMinSum(int* numbers, size_t n, int currentNumber, int* indexes, size_t countIndexes)
{
    int minSum = currentNumber + numbers[indexes[0]];
    int minIndex = indexes[0];

    for (size_t i = 1; i < countIndexes; ++i)
    {
        int currentSum = currentNumber + numbers[indexes[i]];
        
        if (currentSum < minSum)
        {
            minSum = currentSum;
            minIndex = indexes[i];
        }
    }

    /*for (size_t i = 0; i < countIndexes; ++i)
    {
        int currentSum = currentNumber + numbers[indexes[i]];
        if (currentSum == minSum)
        {
            ++countMinSums;
        }
    }*/

    return minIndex;
}