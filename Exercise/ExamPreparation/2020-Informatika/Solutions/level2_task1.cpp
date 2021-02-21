#include <iostream>

size_t myStrLen(const char* str);

void myStrCpy(const char* what, char* where);

void clearMemory(char** words, size_t n);

int myStrCmp(const char* str1, const char* str2);

void searchWord(char** symbols, int k, char** words, int countWords, int i, int j, int& maxLen, char* maxWord, int currentLen, char* currentWord);

void findLongestWord(char** symbols, int k, char** words, int countWords);

bool checkIfWordIsInDict(char** words, int countWords, char* word);

void copyMatrix(char** original, char** copy, int size);

int main ()
{
    int n;

    std::cin >> n;
    std::cin.ignore();

    char** words = new(std::nothrow) char*[n];
    if(!words)
    {
        std::cout << "Memory problem!" << std::endl;
        return 0;
    }
    int countWords = 0;
    for (int i = 0; i < n; ++i)
    {
        char buffer[100];

        std::cin.getline(buffer, 100);

        if(countWords == 0 || myStrCmp(buffer, words[countWords-1]) > 0)
        {
            //std::cout << buffer << std::endl;
            size_t sizeBuffer = myStrLen(buffer);
            words[countWords] = new(std::nothrow) char[sizeBuffer+1];
            if(!words[countWords])
            {
                clearMemory(words, countWords);
                std::cout << "Memory problem!" << std::endl;
                return 0;
            }
            myStrCpy(buffer, words[countWords]);
            ++countWords;
        }
        else
        {
            std::cout << "The word " << '\"' << buffer << '\"' << " is before " << '\"' <<  words[countWords-1] << '\"' <<std::endl;
            return 0;
        }
    }

    int k;

    do
    {
        std::cin >> k;
    } while (k < 2 || k > 5);
    
    char** letters = new(std::nothrow) char*[k];
    if(!letters)
    {
        std::cout << "Memory problem!" << std::endl;
        return 0;
    }
    for (int i = 0; i < k; ++i)
    {
        letters[i] = new(std::nothrow) char[k];
        if(!letters[i])
        {
            clearMemory(letters, i);
            std::cout << "Memory problem!" << std::endl;
            return 0;
        }
    }

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            std::cin >> letters[i][j];
        }
    }

    /*for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            std::cout << letters[i][j] << " ";
        }
        std::cout << std::endl;
    }*/

    findLongestWord(letters, k, words, countWords);

    clearMemory(words, n);
    clearMemory(letters, k);

    return 0;
}

size_t myStrLen(const char* str)
{
    size_t size = 0;

    while(*str)
    {
        ++size;
        ++str;
    }

    return size;
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

void clearMemory(char** words, size_t n)
{
    for (int i = 0; i < n; ++i)
    {
        delete[] words[i];
    }
    delete[] words;
}

int myStrCmp(const char* str1, const char* str2)
{
    while(*str1 && *str2 && *str1 == *str2)
    {
        ++str1;
        ++str2;
    }

    return *str1 - *str2;
}

bool checkIfWordIsInDict(char** words, int countWords, char* word)
{
    for (int i = 0; i < countWords; ++i)
    {
        if (myStrCmp(words[i], word) == 0)
        {
            return true;
        }
    }
    return false;
}

void searchWord(char** symbols, int k, char** words, int countWords, int i, int j, int& maxLen, char* maxWord, int currentLen, char* currentWord)
{
    currentWord[currentLen] = '\0';
    if (checkIfWordIsInDict(words, countWords, currentWord))
    {
        if (currentLen > maxLen)
        {
            maxLen = currentLen;
            myStrCpy(currentWord, maxWord);
        }
    }

    if (i < 0 || j < 0 || i >= k || j >= k)
    {
        return;
    }

    if (symbols[i][j] == '*')
    {
        return;
    }

    char symbol = symbols[i][j];
    char word[100];
    currentWord[currentLen] = symbols[i][j];
    ++currentLen;
    currentWord[currentLen] = '\0';
    myStrCpy(currentWord, word);
    symbols[i][j] = '*';
    searchWord(symbols, k, words, countWords, i+1, j, maxLen, maxWord, currentLen, word);
    searchWord(symbols, k, words, countWords, i-1, j, maxLen, maxWord, currentLen, word);
    searchWord(symbols, k, words, countWords, i, j+1, maxLen, maxWord, currentLen, word);
    searchWord(symbols, k, words, countWords, i, j-1, maxLen, maxWord, currentLen, word);
    searchWord(symbols, k, words, countWords, i+1, j+1, maxLen, maxWord, currentLen, word);
    searchWord(symbols, k, words, countWords, i+1, j-1, maxLen, maxWord, currentLen, word);
    searchWord(symbols, k, words, countWords, i-1, j+1, maxLen, maxWord, currentLen, word);
    searchWord(symbols, k, words, countWords, i-1, j-1, maxLen, maxWord, currentLen, word);
    symbols[i][j] = symbol;
}

void findLongestWord(char** symbols, int k, char** words, int countWords)
{
    char maxWord[100] = {}, currentWord[100] = {};
    int maxLen = 0;
    //searchWord(symbols, k, words, countWords, 0, 0, 0, maxWord, 0, currentWord);
    char** copyOfSymbols = new(std::nothrow) char*[k];
    if(!copyOfSymbols)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    for (int i = 0; i < k; ++i)
    {
        copyOfSymbols[i] = new(std::nothrow) char[k];
        if(!copyOfSymbols[i])
        {
            clearMemory(copyOfSymbols, i);
            std::cout << "Memory problem!" << std::endl;
            return;
        }
    }
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            copyMatrix(symbols, copyOfSymbols, k);
            searchWord(copyOfSymbols, k, words, countWords, i, j, maxLen, maxWord, 0, currentWord);
        }
    }
    clearMemory(copyOfSymbols, k);
    std::cout << maxLen << std::endl;
    std::cout << maxWord << std::endl;
}

void copyMatrix(char** original, char** copy, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            copy[i][j] = original[i][j];
        }
    }
}