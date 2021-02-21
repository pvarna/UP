#include <iostream>

void play(int number, int* allOptions, size_t size, int& counter);

const int* myTryGuess(int guess, int answer);

const int* putDigitsInArray(int number);

void removeElement(int* array, size_t size, int pos);

int* allocateAllOptions ();

int main ()
{
    int number;
    int* allOptions = allocateAllOptions();
    //int counter = 0;
    //std::cin >> number;
    int countOfTimes[20] = {};
    for (int i = 1234; i <= 9876; ++i)
    {
        int ones = i % 10;
        int tens = i / 10 % 10;
        int hundreds = i / 100 % 10;
        int thousands = i / 1000;
        if (ones != 0 && tens != 0 && hundreds != 0 && ones != tens && ones != hundreds && ones != thousands && tens != hundreds && tens != thousands && hundreds != thousands)
        {
            int* allOptions = allocateAllOptions();
            int counterTries = 0;
            play(i, allOptions, 3024, counterTries);
            ++countOfTimes[counterTries];
            delete[] allOptions;
        }
    }

    for (int i = 0; i < 20; ++i)
    {
        std::cout << countOfTimes[i] << " ";
    }

    //play(number, allOptions, 3024, counterTries);

    delete[] allOptions;
    //delete[] test;
    return 0;
}

const int* putDigitsInArray(int number)
{
    int* result = new(std::nothrow) int[4];
    result[0] = number / 1000;
    result[1] = number / 100 % 10;
    result[2] = number / 10 % 10;
    result[3] = number % 10; 

    return result;

}

void play(int number, int* allOptions, size_t size, int& counter)
{
    while (true)
    {   
        ++counter;
        int currentTry;
        if (counter == 1)
        {
            currentTry = 1234;
        }
        else if (counter == 2)
        {
            currentTry = 3857;
        }
        else
        {
            currentTry = allOptions[0];
        }
        
        const int* temp = myTryGuess(currentTry, number);
        if (temp[0] == 4)
        {
            delete[] temp;
            //std::cout << counter << " ";
            return;
        }
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

int* allocateAllOptions ()
{
    int* allOptions = new(std::nothrow) int[3024];
    int counter = 0;
    for (int i = 1234; i <= 9876; ++i)
    {
        int ones = i % 10;
        int tens = i / 10 % 10;
        int hundreds = i / 100 % 10;
        int thousands = i / 1000;
        if (ones != 0 && tens != 0 && hundreds != 0 && ones != tens && ones != hundreds && ones != thousands && tens != hundreds && tens != thousands && hundreds != thousands)
        {
            allOptions[counter] = i;
            ++counter;
        }
    }
    return allOptions;
}