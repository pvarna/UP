#include <iostream>
#include <cstring>

const int MAX_NUMBER_OF_WORDS = 20;
const int MAX_NUMBER_OF_LETTERS = 50;

char ** allocateSentenceOfWords();

void clearSentence(char ** sentence, int numberOfWords);

bool myStrCmp(char* word1, char* word2, int size1, int size2);

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

    for (int i = 0; i < indexWord; ++i)
    {
        int counter = 1;
        if (sentence[i][0] != ' ')
        {
            for (int j = i+1; j < indexWord; ++j)
            {
                if (myStrCmp(sentence[i], sentence[j], numberOfLetters[i], numberOfLetters[j]))
                {
                    ++counter;
                    sentence[j][0] = ' ';
                }
            }
            printWord(sentence[i], numberOfLetters[i]);
            std::cout << " - " << counter << std::endl;
        }
    }
   
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

bool myStrCmp(char* word1, char* word2, int size1, int size2)
{
    if (size1 != size2)
    {
        return false;
    }
    for (int i = 0; i < size1; ++i)
    {
        if (word1[i] != word2[i])
        {
            return false;
        }
    }
    return true;
}

void printWord(char* word, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << word[i];
    }
}