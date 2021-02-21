#include <iostream>
#include "BullsAndCows.h"

// helper function for easier work
const int* putDigitsInArray(int number)
{
    int* result = new(std::nothrow) int[4];
    
    result[0] = number / 1000;
    result[1] = number / 100 % 10;
    result[2] = number / 10 % 10;
    result[3] = number % 10; 

    return result;

}

// my version of the 'TryGuess' function which helps me to find the correct number
const int* myTryGuess(int guess, int answer)
{
    int* result = new(std::nothrow) int[2];

    const int* guessArray = putDigitsInArray(guess);
    const int* answerArray = putDigitsInArray(answer);

    int bulls = 0, cows = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (guessArray[i] == answerArray[j])
            {
                if (i == j)
                {
                    ++bulls;
                }
                else
                {
                    ++cows;
                }
                break;
            }
        }
    }

    result[0] = bulls;
    result[1] = cows;

    delete[] guessArray;
    delete[] answerArray;

    return result;    
}

void removeElement(int* array, size_t size, int pos)
{
    for (int i = pos; i < size-1; ++i)
    {
        array[i] = array[i+1];
    }
}

void play()
{
    size_t size = 3024; // all options are 9*8*7*6 = 3024
    int* allOptions = new(std::nothrow) int[size];

    if(!allOptions)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    int counterElements = 0, counterTries = 0;

    for (int i = 1234; i <= 9876; ++i)
    {
        int ones = i % 10;
        int tens = i / 10 % 10;
        int hundreds = i / 100 % 10;
        int thousands = i / 1000;

        if (ones != 0 && tens != 0 && hundreds != 0 && ones != tens && ones != hundreds && 
            ones != thousands && tens != hundreds && tens != thousands && hundreds != thousands)
        {
            allOptions[counterElements] = i;
            ++counterElements;
        }
    }

    // the idea of the algorthm is to remove all elements from the array of remaining options that do not match
    // with the result given from the 'tryGuess' function
    // each time my guess is the first element of the array expect from the second try when the it is always 3857
    // 3857 is a better number than most of the other options (I found the number extremely luckily :DDD)
    while (true)
    {   
        ++counterTries;
        int currentTry;

        if (counterTries == 2)
        {
            currentTry = 3857;
        }
        else
        {
            currentTry = allOptions[0];
        }
        
        const int* temp = tryGuess(currentTry);
        
        if (temp[0] == 4)
        {
            delete[] temp;
            delete[] allOptions;

            return;
        }

        // removing the elements that do not match with temp[0] bulls and temp[1] cows
        for (int i = 0; i < size; ++i)
        {
            int currentNumber = allOptions[i];
            const int* current = myTryGuess(currentNumber, currentTry);

            if (current[0] != temp[0] || current[1] != temp[1])
            {
                removeElement(allOptions, size, i);
                --size;
                --i;
            }
            delete[] current;
        }

        delete[] temp;
    }
}