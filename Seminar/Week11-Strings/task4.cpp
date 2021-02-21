#include <iostream>
#include <cstring>

const int MAX_NUMBER_OF_WORDS = 20;
const int MAX_NUMBER_OF_LETTERS = 50;

char ** allocateSentenceOfWords();

void clearSentence(char ** sentence, int numberOfWords);

int maxElement(int* array, int size);

void printWord(char* word, int size);

int main ()
{
    char ** sentence = allocateSentenceOfWords();

    char ch;
    int indexLetter = 0, indexWord = 0;
    int numberOfLetters[1000] = {};
    std::cin.get(ch);
    while (ch != '\n')
    {
        if (ch == ' ')
        {
            numberOfLetters[indexWord] = indexLetter;
            indexLetter = 0;
            ++indexWord;
        }
        else
        {
            sentence[indexWord][indexLetter] = ch;
            ++indexLetter;
        }
        std::cin.get(ch);
    }
    numberOfLetters[indexWord] = indexLetter;
    ++indexWord;

    int maxIndex = maxElement(numberOfLetters, indexWord);

    printWord(sentence[maxIndex], numberOfLetters[maxIndex]);
    std::cout << std::endl;
   
    clearSentence(sentence, MAX_NUMBER_OF_WORDS);
    return 0;
}

char ** allocateSentenceOfWords()
{
    char ** sentence = new(std::nothrow) char*[MAX_NUMBER_OF_WORDS];
    if (!sentence)
    {
        return sentence;
    }
    for (int i = 0; i < MAX_NUMBER_OF_WORDS; ++i)
    {
        sentence[i] = new(std::nothrow) char[MAX_NUMBER_OF_LETTERS];
        if (!sentence[i])
        {
            clearSentence(sentence, MAX_NUMBER_OF_WORDS);
            return nullptr;
        }
    }

    return sentence;
}

void clearSentence(char ** sentence, int numberOfWords)
{
    for (int i = 0; i < numberOfWords; ++i)
    {
        delete[] sentence[i];
    }

    delete[] sentence;
}

int maxElement(int* array, int size)
{
    int maxIndex = 0;
    for (int i = 1; i < size; ++i)
    {
        if (array[i] > array[maxIndex])
        {
            maxIndex = i;
        }
    }

    return maxIndex;
}

void printWord(char* word, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << word[i];
    }
}