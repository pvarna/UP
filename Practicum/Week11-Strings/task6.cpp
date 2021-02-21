#include <iostream>

size_t myStrLen(const char* text);

void myStrCpyPtr(char* copy, const char* original);

int myStrStr(const char* where, const char* what);

char* myStrDup(const char* text);

char* replaceEqual(const char* text, const char* thisStr, const char* thatStr);

char* replaceShorter(const char* text, const char* thisStr, const char* thatStr);

char* replaceLonger(const char* text, const char* thisStr, const char* thatStr);

char* removeAnElement(char* text, size_t index); // creates a shortened duplicatе

char* addAnElement(char* text, size_t index); // creates an extended duplicate

int main ()
{
    const char* text = "Tra la la moneyla";
    const char* thisStr = "la";
    const char* thatEqualStr = "XX";
    const char* thatShorterStr = "X";
    const char* thatLongerStr = "XXX"; 

    char* equal = replaceEqual(text, thisStr, thatEqualStr);
    char* shorter = replaceShorter(text, thisStr, thatShorterStr);
    char* longer = replaceLonger(text, thisStr, thatLongerStr);

    std::cout << equal << std::endl;
    std::cout << shorter << std::endl;
    std::cout << longer << std::endl;

    delete[] equal;
    delete[] shorter;
    delete[] longer;
    
    return 0;
}

void myStrCpyPtr(char* copy, const char* original)
{
    while (*copy++ = *original++)
        ;
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

int myStrStr(const char* where, const char* what)
{
    size_t whatLength = myStrLen(what);
    const char* whereEnd = where + myStrLen(where);
    const char* whereStart = where;
    size_t pos;

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
            return (where - whereStart);
        }
        ++where;
    }
    return -1;
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

char* replaceEqual(const char* text, const char* thisStr, const char* thatStr)
{
    char* copy = myStrDup(text);
    int startingIndex = 0;
    size_t lengthThatStr = myStrLen(thatStr);
    int occurence = myStrStr(text+startingIndex, thisStr);

    while (occurence != -1)
    {
        for (int j = 0; j < lengthThatStr; ++j)
        {
            copy[startingIndex+occurence+j] = thatStr[j];
        }
        startingIndex += occurence+lengthThatStr;
        occurence = myStrStr(text+startingIndex, thisStr);
    }
    
    return copy;
}

char* replaceShorter(const char* text, const char* thisStr, const char* thatStr)
{
    char* copy = myStrDup(text);
    int startingIndex = 0;
    size_t lengthThatStr = myStrLen(thatStr);
    size_t lengthThisStr = myStrLen(thisStr);
    size_t difference = lengthThisStr - lengthThatStr;
    int occurrence = myStrStr(text+startingIndex, thisStr);
    
    while (occurrence != -1)
    {
        for (int j = 0; j < difference; ++j)
        {
            copy = removeAnElement(copy, startingIndex+occurrence);
        }
        for (int j = 0; j < lengthThatStr; ++j)
        {
            copy[startingIndex+occurrence+j] = thatStr[j];
        }
        startingIndex += occurrence+lengthThatStr;
        occurrence = myStrStr(copy+startingIndex, thisStr);
    }
    
    return copy;
}

char* replaceLonger(const char* text, const char* thisStr, const char* thatStr)
{
    char* copy = myStrDup(text);
    int startingIndex = 0;
    size_t lengthThatStr = myStrLen(thatStr);
    size_t lengthThisStr = myStrLen(thisStr);
    size_t difference = lengthThatStr - lengthThisStr;
    int occurrence = myStrStr(text+startingIndex, thisStr);
    
    while (occurrence != -1)
    {
        for (int j = 0; j < difference; ++j)
        {
            copy = addAnElement(copy, startingIndex+occurrence+lengthThisStr);
        }
        for (int j = 0; j < lengthThatStr; ++j)
        {
            copy[startingIndex+occurrence+j] = thatStr[j];
        }
        startingIndex += occurrence+lengthThatStr;
        occurrence = myStrStr(copy+startingIndex, thisStr);
    }
    
    return copy;
}

char* removeAnElement(char* text, size_t index)
{
    char* result = new(std::nothrow) char[myStrLen(text)];

    for (int i = 0; i < index; ++i)
    {
        result[i] = text[i];
    }
    for (int i = index+1; i < myStrLen(text); ++i)
    {
        result[i-1] = text[i];
    }
    result[myStrLen(text)-1] = '\0';

    delete[] text;
    return result;
}

char* addAnElement(char* text, size_t index)
{
    char* result = new(std::nothrow) char[myStrLen(text)+2];

    for (int i = 0; i < index; ++i)
    {
        result[i] = text[i];
    }
    result[index] = ' ';
    for (int i = index+1; i <= myStrLen(text); ++i)
    {
        result[i] = text[i-1];
    }
    result[myStrLen(text)+1] = '\0';

    delete[] text;
    return result;
}