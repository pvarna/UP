#include <iostream>

bool isFirstNumberSmallerByBits(int firstNumber, int secondNumber, bool& areEqual);

void countOnes(int number, int& even, int& odd);

void sortNumbers(int* numbers, int n);

void removeEqualElements(int* numbers, int& n);

void removeAt(int* numbers, int n, int index);

int main ()
{
    int n;

    //std::cout << std::boolalpha << isFirstNumberSmallerByBits(5, 8) << std::endl;

    std::cin >> n;

    int* numbers = new(std::nothrow) int[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
        /*if (i > 0)
        {
            std::cout << std::boolalpha << isFirstNumberSmallerByBits(numbers[i-1], numbers[i]) << std::endl;
        }*/
    }

    sortNumbers(numbers, n);

    for (int i = 0; i < n; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    removeEqualElements(numbers, n);

    for (int i = 0; i < n; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    delete[] numbers;

    return 0;
}

bool isFirstNumberSmallerByBits(int firstNumber, int secondNumber, bool& areEqual)
{
    int countEvenBits1, countOddBits1, countEvenBits2, countOddBits2;
    
    countOnes(firstNumber, countEvenBits1, countOddBits1);
    countOnes(secondNumber, countEvenBits2, countOddBits2);

    /*std::cout << countEvenBits1 << " " << countOddBits1 << std::endl;
    std::cout << countEvenBits2 << " " << countOddBits2 << std::endl;*/

    if (countEvenBits1 == countEvenBits2 && countOddBits1 == countOddBits2)
    {
        areEqual = true;
    }

    return ((countEvenBits1 < countEvenBits2) || (countEvenBits1 == countEvenBits2 && countOddBits1 < countOddBits2));
}

void countOnes(int number, int& even, int& odd)
{
    even = 0;
    odd = 0;
    int tempEven = number;

    while(tempEven)
    {
        if (tempEven & 1)
        {
            ++even;
        }
        tempEven = (tempEven >> 2);
    }

    int tempOdd = (number >> 1);
    while(tempOdd)
    {
        if (tempOdd & 1)
        {
            ++odd;
        }
        tempOdd = (tempOdd >> 2);
    }
}

void sortNumbers(int* numbers, int n)
{
    bool isSorted = true;
    bool tempBool = false;
    int start = 0;
    do
    {
        isSorted = true;
        for (int i = n-1; i > start; --i)
        {
            if (!isFirstNumberSmallerByBits(numbers[i], numbers[i-1], tempBool))
            {
                int temp = numbers[i];
                numbers[i] = numbers[i-1];
                numbers[i-1] = temp;
                isSorted = false;
            }
        }
        ++start;
    } while (!isSorted);   
}

void removeEqualElements(int* numbers, int& n)
{
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            bool areEqual = false;
            if (!isFirstNumberSmallerByBits(numbers[i], numbers[j], areEqual))
            {
                if (areEqual)
                {
                    removeAt(numbers, n, j);
                    --n;
                    --j;
                    removeAt(numbers, n, i);
                    --i;
                    --n;
                }
            }
        }
    }
}

void removeAt(int* numbers, int n, int index)
{
    for (int i = index; i < n-1; ++i)
    {
        numbers[i] = numbers[i+1];
    }
}