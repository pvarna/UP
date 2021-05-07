//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в програмирането 2020/21
// Контролно 2
// 2020-01-17
//
// Начален час: 10:00 ч.
// Име: Петър Станомиров Колев
// ФН: 82214
// Специалност: Компютърни науки
// Курс: 1
// Административна група: 4
// Използван компилатор: GCC
//

#include <iostream>

const int MAX_LINE_SIZE = 100;

void clearWords(char** words, size_t n);

bool readDict(char**& plainWords, char**& cryptedWords, size_t& n);

size_t myStrSize(const char* str);

void myStrCpy(const char* what, char* where);

bool myStrCmp(const char* str1, const char* str2);

char* readInputText(size_t& m);

bool isLetter(char ch);

char* translate(char* text, size_t m, char** plainWords, char** cryptedWords, size_t n);

int searchInDict(char* word, char** plainWords, size_t n);

char toLower(char ch);

char* doTranslation(size_t currentSize, char* word, char* beginning, char* ending, char** cryptedWords, size_t index);

int main ()
{
    size_t n;
    char** plain;
    char** crypt;

    bool validDict = readDict(plain, crypt, n);
    if (!validDict)
    {
        std::cout << "Problem while reading dictionary!" << std::endl;
        return 1;
    }

    size_t m;

    char* text = readInputText(m);
    if(!text)
    {
        std::cout << "Problem while reading the text!" << std::endl;
        return 1;
    }

    char* newText = translate(text, m, plain, crypt, n);

    std::cout << newText << std::endl;


    clearWords(plain, n);
    clearWords(crypt, n);
    delete[] text;
    delete[] newText;

    return 0;
}

bool readDict(char**& plainWords, char**& cryptedWords, size_t& n)
{
    std::cin >> n;
    plainWords = new(std::nothrow) char*[n];
    cryptedWords = new(std::nothrow) char*[n];
    if(!plainWords || !cryptedWords)
    {
        n = 0;
        clearWords(plainWords, n);
        clearWords(cryptedWords, n);
        return false;
    }

    for (size_t i = 0; i < n; ++i)
    {
        char buffer[MAX_LINE_SIZE+1];
        std::cin >> buffer;
        plainWords[i] = new(std::nothrow) char[myStrSize(buffer)+1];
        if(!plainWords[i])
        {
            clearWords(plainWords, i+1);
            clearWords(cryptedWords, i+1);
            return false;
        }
        else
        {
            myStrCpy(buffer, plainWords[i]);
        }
        std::cin >> buffer;
        cryptedWords[i] = new(std::nothrow) char[myStrSize(buffer)+1];
        if(!cryptedWords[i])
        {
            clearWords(plainWords, i+1);
            clearWords(cryptedWords, i+1);
            return false;
        }
        else
        {
            myStrCpy(buffer, cryptedWords[i]);
        }
    }
    return true;
}

size_t myStrSize(const char* str)
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
    size_t pos = 0;
    while(what[pos])
    {
        where[pos] = what[pos];
        ++pos;
    }
    where[pos] = '\0';
}

bool myStrCmp(const char* str1, const char* str2)
{
    while (*str1)
    {
        if (toLower(*str1) != toLower(*str2))
        {
            return false;
        }
        ++str1;
        ++str2;
    }
    if (!(*str2))
    {
        return true;
    }
    return false;
}

void clearWords(char** words, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        delete[] words[i];
    }
    delete[] words;
}

char* readInputText(size_t& m)
{
    std::cin >> m;
    std::cin.ignore();
    
    char* text = new(std::nothrow) char[m];
    if (text)
    {
        for (size_t i = 0; i < m; ++i)
        {
            text[i] = std::cin.get();
        }
        text[m] = '\0';
    }

    return text;
}

bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z')
        || (ch >= 'A' && ch <= 'Z');
}


int searchInDict(char* word, char** plainWords, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        if (myStrCmp(word, plainWords[i]))
        {
            return i;
        }
    }

    return -1;
}

char* translate(char* text, size_t m, char** plainWords, char** cryptedWords, size_t n)
{
    size_t currentSize = m;
    char* currentText = new(std::nothrow) char[m+1];
    myStrCpy(text, currentText);
    size_t startWord = 0;
    size_t endWord = 0;

    while (currentText[startWord])
    {
        while (!isLetter(currentText[startWord]))
        {
            ++startWord;
        }
        if (currentText[startWord])
        {
            endWord = startWord;
            while (isLetter(currentText[endWord]))
            {
                ++endWord;
            }
            size_t sizeWord = endWord - startWord;
            char* currentWord = new(std::nothrow) char[sizeWord+1];
            int counterCurrentWord = 0;
            for (size_t i = startWord; i < endWord; ++i)
            {
                currentWord[counterCurrentWord] = currentText[i];
                ++counterCurrentWord;
            }
            currentWord[counterCurrentWord] = '\0';
            //std::cout << currentWord << std::endl;
            int occurre = searchInDict(currentWord, plainWords, n);
            if (occurre >= 0)
            {
                size_t sizeBeginning = startWord;
                size_t sizeEnding = currentSize - endWord;
                char* beginning = new(std::nothrow) char[sizeBeginning+1];
                for (size_t i = 0; i < startWord; ++i)
                {
                    beginning[i] = currentText[i];
                }
                beginning[sizeBeginning] = '\0';
                char* ending = new(std::nothrow) char[sizeEnding+1];
                int counterEnging = 0;
                for (size_t i = endWord; i < currentSize; ++i)
                {
                    ending[counterEnging] = currentText[i];
                    ++counterEnging;
                }
                ending[sizeEnding] = '\0';
                delete[] currentText;
                currentText = doTranslation(currentSize, currentWord, beginning, ending, cryptedWords, occurre);
                currentSize = myStrSize(currentText);
                delete[] beginning;
                delete[] ending;
                startWord = 0;
                endWord = 0;
            }
            else
            {
                while (isLetter(currentText[startWord]))
                {
                    ++startWord;
                }
            }
            delete[] currentWord;
        }
    }

    return currentText;
}

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch + ('a' - 'A');
    }
    return ch;
}

char* doTranslation(size_t currentSize, char* word, char* beginning, char* ending, char** cryptedWords, size_t index)
{
    size_t sizeWord = myStrSize(word);
    size_t sizeCryptedWord = myStrSize(cryptedWords[index]);
    size_t sizeBeggining = myStrSize(beginning);
    size_t sizeEnding = myStrSize(ending);
    int difference = sizeWord - sizeCryptedWord;
    currentSize -= difference;
    char* newText = new(std::nothrow) char[currentSize+1];
    int counter = 0;
    for (size_t i = 0; i < sizeBeggining; ++i)
    {
        newText[counter] = beginning[i];
        ++counter;
    }
    for (size_t i = 0; i < sizeCryptedWord; ++i)
    {
        newText[counter] = cryptedWords[index][i];
        ++counter;
    }
    for (size_t i = 0; i < sizeEnding; ++i)
    {
        newText[counter] = ending[i];
        ++counter;
    }
    newText[counter] = '\0';

    return newText;
}