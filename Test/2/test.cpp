#include <iostream>

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch + ('a' - 'A');
    }
    return ch;
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

int main ()
{
    char str1[100], str2[100];

    std::cin >> str1 >> str2;

    std::cout << std::boolalpha << myStrCmp(str1, str2) << std::endl;

    return 0;
}