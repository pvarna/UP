#include <iostream>

const int MAX_NUMBER_OF_WORDS = 1000;
const int MAX_NUMBER_OF_LETTERS = 20;

int readText(char text[][MAX_NUMBER_OF_LETTERS]);

size_t myStrLen(char word[]);

void myStrCpy(char word1[], char word2[]);

int main ()
{
    char text[MAX_NUMBER_OF_WORDS][MAX_NUMBER_OF_LETTERS];

    int numberOfWords = readText(text);

    int maxLenght = 1;
    char longestWord[MAX_NUMBER_OF_LETTERS];

    myStrCpy(text[0], longestWord);

    for (int i = 1; i < numberOfWords; ++i)
    {
        if (myStrLen(text[i]) > maxLenght)
        {
            maxLenght = myStrLen(text[i]);
            myStrCpy(text[i], longestWord);
        }
    }

    for (int i = 0; i < myStrLen(longestWord); ++i)
    {
        std::cout << longestWord[i];
    }

    std::cout << std::endl;

    return 0;
}

int readText(char text[][MAX_NUMBER_OF_LETTERS])
{
    int i = 0;
    while(true)
    {
        std::cin >> text[i];
        if (text[i][myStrLen(text[i])-1] == '.')
        {
            break;
        }
        ++i;
    }
    return i;
}

size_t myStrLen(char word[])
{
    size_t len = 0;
    while (word[len])
    {
        ++len;
    }
    return len;
}

void myStrCpy(char word1[], char word2[])
{
    size_t size1 = myStrLen(word1);
    for (size_t i = 0; i < size1; ++i)
    {
        word2[i] = word1[i];
    }
    word2[size1] = '\0';
}