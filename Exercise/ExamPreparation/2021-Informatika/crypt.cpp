#include <iostream>

bool readCryptingTable(char*& letters, char**& strings, int& k);

void clearWords(char** words, int n);

size_t myStrLen(const char* str);

void myStrCpy(const char* what, char* where);

bool readStrings(char**& strings, int& n);

int main ()
{
    int k;
    char* letters;
    char** strings;

    bool validTable = readCryptingTable(letters, strings, k);
    if (!validTable)
    {
        std::cout << "Memory problem!" << std::endl;
        return 1;
    }

    int n;
    char** unecryptedStrings;

    bool validUncryptedStrings = readStrings(unecryptedStrings, n);

    int m;
    char** cryptedStrings;

    bool validCryptedStrings = readStrings(cryptedStrings, m);

    for (int i = 0; i < n; ++i)
    {
        std::cout << unecryptedStrings[i] << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < m; ++i)
    {
        std::cout << cryptedStrings[i] << std::endl;
    }

    clearWords(strings, k);
    clearWords(unecryptedStrings, n);
    clearWords(cryptedStrings, m);
    delete[] letters;

    return 0;
}

bool readCryptingTable(char*& letters, char**& strings, int& k)
{
    std::cin >> k;
    std::cin.ignore();

    letters = new(std::nothrow) char[k];
    strings = new(std::nothrow) char*[k];

    if (!letters || !strings)
    {
        clearWords(strings, 0);
        delete[] letters;
        return false;
    }

    for (int i = 0; i < k; ++i)
    {
        letters[i] = std::cin.get();
        std::cin.ignore();

        char buffer[100];
        std::cin >> buffer;
        std::cin.ignore();
        size_t sizeBuffer = myStrLen(buffer);
        strings[i] = new(std::nothrow) char[sizeBuffer+1];
        if (!strings[i])
        {
            clearWords(strings, i+1);
            delete[] letters;
            return false;
        }
        myStrCpy(buffer, strings[i]);
    }

    return true;
}

void clearWords(char** words, int n)
{
    for (int i = 0; i < n; ++i)
    {
        delete[] words[i];
    }
    delete[] words;
}

size_t myStrLen(const char* str)
{
    size_t n = 0;
    while (str[n])
    {
        ++n;
    }

    return n;
}

void myStrCpy(const char* what, char* where)
{
    size_t n = 0;

    while (what[n])
    {
        where[n] = what[n];
        ++n;
    }

    where[n] = '\0';
}

bool readStrings(char**& strings, int& n)
{
    std::cin >> n;
    std::cin.ignore();

    strings = new(std::nothrow) char*[n];
    if(!strings)
    {
        clearWords(strings, 0);
        return false;
    }

    for (int i = 0; i < n; ++i)
    {
        char buffer[1000];
        std::cin.getline(buffer, 1000);
        //std::cin.ignore();

        size_t sizeBuffer = myStrLen(buffer);
        strings[i] = new(std::nothrow) char[sizeBuffer+1]; 
        if (!strings[i])
        {
            clearWords(strings, i+1);
            return false;
        }
        myStrCpy(buffer, strings[i]);
    }

    return true;
}