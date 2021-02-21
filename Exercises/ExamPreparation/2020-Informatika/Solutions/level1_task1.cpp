#include <iostream>

const int MAX_TEXT_SIZE = 1024*1024;

const int COUNT_OF_WORDS = 1024;

const int COUNT_OF_LETTERS = 64;

size_t myStrLen(const char* str);

void myStrCpy(const char* what, char* where);

int myStrCmp(const char* str1, const char* str2);

bool isLetter(char ch);

int countOfWords(const char* text);

int extractWords(const char* text, char distinctWords[][COUNT_OF_LETTERS], int* counter);

int wordTaken(char distinctWords[][COUNT_OF_LETTERS], size_t wordsSoFar, const char* word);

char toLower(char ch);

int maxFrom(char distinctWords[][COUNT_OF_LETTERS],  int* counter, int from, int to);

void sortWords(char distinctWords[][COUNT_OF_LETTERS], int* counter, size_t size);

int main()
{
    static char text[MAX_TEXT_SIZE];
    static char distinctWords[COUNT_OF_WORDS][COUNT_OF_LETTERS];
    static int counter[COUNT_OF_WORDS] = {};

    std::cin.getline(text, 1024*1024, '#');

    std::cout << text << std::endl;

    std::cout << "All words - " << countOfWords(text) << std::endl;

    int countDistinctWords = extractWords(text, distinctWords, counter);
    std::cout << "Distinct words - " << countDistinctWords << std::endl;

    sortWords(distinctWords, counter, countDistinctWords);

    for (int i = 0; i < countDistinctWords; ++i)
    {
        std::cout << distinctWords[i] << " - " << counter[i] << std::endl;
    }


    return 0;
}

size_t myStrLen(const char* str)
{
    size_t n = 0;

    while(str[n])
    {
        ++n;
    }

    return n;
}

void myStrCpy(const char* what, char* where)
{
    size_t size = myStrLen(what);

    for (size_t i = 0; i < size; ++i)
    {
        where[i] = what[i];
    }
    where[size] = '\0';
}

int myStrCmp(const char* str1, const char* str2)
{
    while (*str1 && *str2 && *str1 == *str2)
    {
        ++str1;
        ++str2;
    }

    return *str1 - *str2;
}

bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch == '-');
}

int countOfWords(const char* text)
{
    int count = 0;
    while(*text)
    {
        while(*text && !isLetter(*text))
        {
            ++text;
        }
        if(*text)
        {
            ++count;
        }
        while(isLetter(*text))
        {
            ++text;
        }
    }

    return count;
}

int extractWords(const char* text, char distinctWords[][COUNT_OF_LETTERS], int* counter)
{
    int countOfDistinctWords = 0;
    while(*text)
    {
        while(*text && !isLetter(*text))
        {
            ++text;
        } 
        if(*text)
        {
            const char* start = text;
            while(isLetter(*text))
            {
                ++text;
            }
            int wordLen = text - start;
            char word[64];
            for (int i = 0; i < wordLen; ++i)
            {
                word[i] = toLower(start[i]);
            }
            word[wordLen] = '\0';
            //std::cout << word << std::endl;
            int index = wordTaken(distinctWords, countOfDistinctWords, word);
            if (index == -1)
            {
                myStrCpy(word, distinctWords[countOfDistinctWords]);
                counter[countOfDistinctWords] = 1;
                ++countOfDistinctWords;
            }
            else
            {
                ++counter[index];
            }
        }
    }

    return countOfDistinctWords;
}

int wordTaken(char distinctWords[][COUNT_OF_LETTERS], size_t wordsSoFar, const char* word)
{
    for (int i = 0; i < wordsSoFar; ++i)
    {
        if(!myStrCmp(distinctWords[i], word))
        {
            return i;
        }
    }
    return -1;
}

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch += ('a'-'A');
    }

    return ch;
}

int maxFrom(char distinctWords[][COUNT_OF_LETTERS],  int* counter, int from, int to)
{
    int max = from;
    for (int i = from+1; i < to; ++i)
    {
        if ((counter[i] > counter[max]) ||
           (counter[i] == counter[max] && myStrCmp(distinctWords[i], distinctWords[max]) < 0))
        {
            max = i;
        }
    }

    return max;
}

void sortWords(char distinctWords[][COUNT_OF_LETTERS], int* counter, size_t size)
{
    for (int i = 0; i < size-1; ++i)
    {
        int maxIndex = maxFrom(distinctWords, counter, i, size);
        std::swap(counter[i], counter[maxIndex]);
        char buffer[COUNT_OF_LETTERS];
        myStrCpy(distinctWords[i], buffer);
        myStrCpy(distinctWords[maxIndex], distinctWords[i]);
        myStrCpy(buffer, distinctWords[maxIndex]);
    }
}