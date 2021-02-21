#include <iostream>

const int MAX_ARRAY_SIZE = 20;

const int NUMBER_Of_DIGITS = 10;

void readString(char string[]);

size_t myStrLen(char string[]);

void countDigits(char string[], size_t size, int counter[]);

void printString(char string[], size_t size);

int main ()
{
    char firstRowOfDigits[MAX_ARRAY_SIZE], secondRowOfDigits[MAX_ARRAY_SIZE];
    int counterOfDigits1[NUMBER_Of_DIGITS] = {}, counterOfDigits2[NUMBER_Of_DIGITS] = {};
    int counter[NUMBER_Of_DIGITS] = {};
    char result[MAX_ARRAY_SIZE];
    int countElements = 0;

    readString(firstRowOfDigits);
    readString(secondRowOfDigits);

    size_t size1, size2;
    size1 = myStrLen(firstRowOfDigits);
    size2 = myStrLen(secondRowOfDigits);

    countDigits(firstRowOfDigits, size1, counterOfDigits1);
    countDigits(secondRowOfDigits, size2, counterOfDigits2);

    for (int i = 0; i < 10; ++i)
    {
        counter[i] = (counterOfDigits1[i] < counterOfDigits2[i]) ? counterOfDigits1[i] : counterOfDigits2[i];
    }

    for (int i = 9; i >= 0; --i)
    {
        for (int j = 0; j < counter[i]; ++j)
        {
            result[countElements] = '0'+i;
            ++countElements;
        }
    }

    printString(result, countElements);

    return 0;
}

void readString(char string[])
{
    std::cin >> string;
}

size_t myStrLen(char string[])
{
    size_t len = 0;

    while (string[len])
    {
        ++len;
    }

    return len;
}

void countDigits(char string[], size_t size, int counter[])
{
    for (size_t i = 0; i < size; ++i)
    {
        ++counter[string[i]-'0'];
    }
}

void printString(char string[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << string[i];
    }
    std::cout << std::endl;
}