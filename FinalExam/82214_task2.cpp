//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Практически изпит - задачи
// 2021-02-08
//
// Име: Петър Станомиров Колев
// ФН: 82214
// Специалност: Компютърни науки, 1 поток
// Курс: 1
// Административна група: 4
// Използван компилатор: GCC
//

#include <iostream>

const int MAX_SIZE = 10*1024*1024;

size_t myStrLen(const char* str);

void myStrCpy(const char* what, char* where);

int myStrCmp(const char* str1, const char* str2);

char toLower(char ch);

void removeAdditionalSpaces(char* str);

void removeAt(char* str, int index);

bool isLetter(char ch);

bool isPrefix(char* word, char* text);

char* myStrStr(char* what, char* where);

int main ()
{
    static char buffer[MAX_SIZE];

    bool threeMarks = false;
    int counter = 0;
    int countOfConsecutiveMarks = 0;
    while (!threeMarks && counter <= MAX_SIZE)
    {
        buffer[counter] = std::cin.get();
        if (buffer[counter] == '!')
        {
            ++countOfConsecutiveMarks;
        }
        else
        {
            countOfConsecutiveMarks = 0;
        }

        if (countOfConsecutiveMarks == 3)
        {
            threeMarks = true;
        }

        ++counter;
    }

    size_t sizeBuffer = myStrLen(buffer);

    char* text = new(std::nothrow) char[sizeBuffer+1];
    myStrCpy(buffer, text);

    std::cout << std::endl;
    std::cout << text << std::endl;

    int countOfSentences = 0;

    bool startOfBrackets = false;
    bool startOfKavichki = false;
    bool firstKavichki = true;
    for (int i = 0; i < sizeBuffer-3; ++i)
    {
        if (text[i] == '(')
        {
            startOfBrackets = true;
        }
        if (text[i] == ')')
        {
            startOfBrackets = false;
        }
        if (text[i] == '\"' && firstKavichki)
        {
            firstKavichki = false;
            startOfKavichki = true;
        }
        if (text[i] == '\"' && !firstKavichki)
        {
            startOfKavichki = false;
            firstKavichki = true;
        }
        if ((text[i] == '.' || text[i] == '!' || text[i] == '?') && !startOfBrackets && !startOfKavichki
         && (text[i+1] == ' ' || text[i+1] == '\t' || text[i+1] =='\n'))
        {
            ++countOfSentences;            
        }
    }

    std::cout << countOfSentences << std::endl;

    char** sentences = new(std::nothrow) char*[countOfSentences];
    if (!sentences)
    {
        std::cout << "Memory problem!" << std::endl;
        delete[] sentences;
        return 1;
    }
    for (int i = 0; i < countOfSentences; ++i)
    {
        char buffer[1000];
        int countBuffer = 0;
    }

    delete[] text;
    for (int i = 0; i < countOfSentences; ++i)
    {
        delete[] sentences[i];
    }
    delete[] sentences;

    return 0;
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

int myStrCmp(const char* str1, const char* str2)
{
    while (*str1 && *str2 && toLower(*str1) == toLower(*str2))
    {
        ++str1;
        ++str2;
    }

    return toLower(*str1) - toLower(*str2);
}

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch + ('a' - 'A');
    }

    return ch;
}

void removeAt(char* str, int index)
{
    size_t size = myStrLen(str);

    for (int i = index; i < size-1; ++i)
    {
        str[i] = str[i+1];
    }
    str[size-1] = '\0';
}

void removeAdditionalSpaces(char* str)
{
    size_t size = myStrLen(str);

    while (str[0] == ' ')
    {
        removeAt(str, 0);
        --size;
    }

    for (int i = 1; i < size; ++i)
    {
        if (str[i] == ' ' && str[i-1] == ' ')
        {
            removeAt(str, i);
            --size;
            --i;   
        }
    }

    std::cout << str << std::endl;
}

bool isLetter(char ch)
{
    return (ch >= 'A' && ch <= 'Z')
        || (ch >= 'a' && ch <= 'z')
        || (ch == '\"')
        || (ch >= '0' && ch <= '9');
}

bool isPrefix(char* word, char* text)
{
    if(!*word)
    {
        return true;
    }

    if(!*text)
    {
        return false;
    }

    return *word == *text && isPrefix(word+1, text+1);
}

char* myStrStr(char* what, char* where)
{
    if (!*where)
    {
        return nullptr;
    }
    if (isPrefix(what, where))
    {
        return where;
    }
    return myStrStr(what, where+1);
}