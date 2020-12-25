#include <iostream>
#include <cstring>

const int MAX_NUMBER_OF_WORDS = 20;
const int MAX_NUMBER_OF_LETTERS = 50;

char ** allocateSentenceOfWords();

void clearSentence(char ** sentence, int numberOfWords);

void removeWord(char ** sentence, int numberOfWords, int* sizes, int k);

void myStrCpy(char* word1, char* word2, int size1);

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

    std::cout << "Which word doyou want to remove? ";

    int k;
    std::cin >> k;

    removeWord(sentence, indexWord, numberOfLetters, k-1);
    --indexWord;

    for (int i = 0; i < indexWord; ++i)
    {
        printWord(sentence[i], numberOfLetters[i]);
        std::cout << " ";       
    }
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

void removeWord(char ** sentence, int numberOfWords, int* sizes, int k)
{
    for (int i = k; i < numberOfWords; ++i)
    {
        myStrCpy(sentence[i+1], sentence[i], sizes[i+1]);
        sizes[i] = sizes[i+1];
    }
}

void myStrCpy(char* word1, char* word2, int size1)
{
    for (int i = 0; i < size1; ++i)
    {
        word2[i] = word1[i];
    }
}

void printWord(char* word, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << word[i];
    }
}