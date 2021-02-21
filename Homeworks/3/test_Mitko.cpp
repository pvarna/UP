#include <iostream>

void play(int number, int* allOptions, size_t size, int& counter);

const int* myTryGuess(int guess, int answer);

const int* putDigitsInArray(int number);

void removeElement(int* array, size_t size, int pos);

int is5678Avilable(int* array, size_t size);

int main ()
{
    int number;
    int* allOptions = new(std::nothrow) int[3024];
    int counter = 0;
    std::cout << "Enter your number: ";
    std::cin >> number;
    std::cout << "Thank you! I will try to guess it as quickly as possible" << std::endl;

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

    /*const int* test = myTryGuess(1234, number);

    std::cout << "Bulls: " << test[0] << std::endl;
    std::cout << "Cows: " << test[1] << std::endl;*/
    int counterTries = 0;

    play(number, allOptions, 3024, counterTries);

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
        int currentTry = allOptions[0];
        if (counter == 2)
        {
            currentTry = test;
        }
        std::cout << "Try number " << counter << ": " << currentTry << std::endl;
        const int* temp = myTryGuess(currentTry, number);
        if (temp[0] == 4)
        {
            delete[] temp;
            std::cout << "Congratulations! You have guessed the number on the " << counter << " attempt." << std::endl;
            return;
        }
        std::cout << "Wrong!" << std::endl;
        std::cout << "Bulls: " << temp[0] << std::endl;
        std::cout << "Cows: " << temp[1] << std::endl;
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

int is5678Avilable(int* array, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i] == 5678)
        {
            return i;
        }
    }
    return -1;
}