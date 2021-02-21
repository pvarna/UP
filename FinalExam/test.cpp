#include <iostream>

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

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch + ('a' - 'A');
    }

    return ch;
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

int main ()
{
    char str1[100], str2[100];

    std::cin.getline(str1, 100);

    removeAdditionalSpaces(str1);

    return 0;
}