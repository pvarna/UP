#include <iostream>
#include <cstring>

typedef char (*mainFunc) (char ch);

char toUpper (char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        ch -= ('a'-'A');
    }
    return ch;
}

char toLower (char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch += ('a'-'A');
    }
    return ch;
}

char doFormatting (mainFunc fn, char ch)
{
    return fn(ch);
}

int main ()
{
    char text[100];

    std::cin.getline(text, 100);

    size_t size = strlen(text);

    for (int i = 0; i < size; ++i)
    {
        std::cout << doFormatting(toLower, text[i]);
    }
    std::cout << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << doFormatting(toUpper, text[i]);
    }
    std::cout << std::endl;

    return 0;
}
