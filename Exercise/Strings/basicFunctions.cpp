#include <iostream>

size_t myStrLen(const char* text);

void myStrCpy(char* copy, const char* original);

void myStrCpyPtr(char* copy, const char* original);

int myStrCmp(const char* text1, const char* text2);

char* myStrDup(const char* text);

bool isLetter(char ch);

int wordCount(const char* text);

int extractWords(const char* text, char *** wordsPtr);

const char* myStrStr(const char* where, const char* what);

int main ()
{
    const char* text = "My name is Peter and I am good at maths and programming, I do not like English";

    size_t length = myStrLen(text);

    char* copy = myStrDup(text);

    std::cout << "Number of characters: " <<length << std::endl;
    std::cout << text << std::endl;

    std::cout << copy << std::endl;

    int countOfWords = wordCount(text);
    std::cout << "Number of words: " << countOfWords << std::endl;

    const char* word = "Peter";
    std::cout << myStrStr(text, word) << std::endl;

    char ** words;
    int countOfExtractedWords = extractWords(text, &words);

    if (countOfExtractedWords != countOfWords)
    {
        std::cout << "Not all words extracted!" << std::endl;
    }

    for (int i = 0; i < countOfExtractedWords; ++i)
    {
        std::cout << words[i] << std::endl;
    }

    delete[] copy;
    for (int i = 0; i < countOfExtractedWords; ++i)
    {
        delete[] words[i];
    }
    delete[] words;

    return 0;
}

size_t myStrLen(const char* text)
{
    size_t length = 0;
    while(text[length])
    {
        ++length;
    }
    return length;
}

void myStrCpy(char* copy, const char* original)
{
    int pos = 0;
    while (original[pos])
    {
        copy[pos] = original[pos];
        ++pos;
    }
}

void myStrCpyPtr(char* copy, const char* original)
{
    while (*copy++ = *original++)
        ;
}

// Compares two strings in lexicographic order
// The result is 0 if the strings are equal,
// negative, if the first is before the second
// and positive in the other case.
int myStrCmp(const char* text1, const char* text2)
{
    while (text1 && text2 && *text1 == *text2)
    {
        ++text1;
        ++text2;
    }

    return *text1 - *text2;
}

char* myStrDup(const char* text)
{
    char* duplicate = new(std::nothrow) char[myStrLen(text)+1];
    if (!duplicate)
    {
        return nullptr;
    }
    myStrCpyPtr(duplicate, text);

    return duplicate;
}

bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
}

int wordCount(const char* text)
{
    int counter = 0;
    while (*text)
    {
        while (*text && !isLetter(*text)) // skip symbols to the beginning of a word
        {
            ++text;
        }
        if (*text) // if there is a word, count it
        {
            ++counter;
        }
        while(isLetter(*text)) // skip to the end of the word
        {
            ++text;
        }
    }
    
    return counter;
}

const char* myStrStr(const char* where, const char* what)
{
    size_t whatLength = myStrLen(what);
    size_t pos;
    const char* whereEnd = where + myStrLen(where);

    while (where + whatLength <= whereEnd)
    {
        for (pos = 0; pos < whatLength; ++pos)
        {
            if (where[pos] != what[pos])
            {
                break;
            }
        }
        if (!what[pos])
        {
            return where;
        }
        ++where;
    }
    return nullptr; 
}

int extractWords(const char* text, char *** wordsPtr)
{
    int countOfWords = wordCount(text); // found the count of the words
    *wordsPtr = new(std::nothrow) char*[countOfWords]; // allocate memory for the array of words
    if (!wordsPtr)
    {
        std::cout << "Memory allocation failed" << std::endl;
        return 0;
    }

    for (int i = 0; i < countOfWords; ++i) // for each word
    {
        while (*text && !isLetter(*text)) // skip symbols to the beginning of a word
        {
            ++text;
        }
        if (*text) // if there is any
        {
            const char* start = text;

            while(isLetter(*text)) // go to the end of the word
            {
                ++text;
            }

            int lengthOfWord = text - start; // calculate the length of the word
            (*wordsPtr)[i] = new(std::nothrow) char[lengthOfWord+1]; // allocate memory fot the word

            if (!(*wordsPtr)[i]) // if the allocation fails
            {
                std::cout << "No memory for word " << i+1;
                return i; // return the number of successfully allocated words
            }

            for (int pos = 0; pos < lengthOfWord; ++pos) // copy the word
            {
                (*wordsPtr)[i][pos] = start[pos];
            }
            (*wordsPtr)[i][lengthOfWord] = '\0'; // put a terminal symbol at the end
        }
    }

    return countOfWords;
}