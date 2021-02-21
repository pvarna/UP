#include <iostream>

const int MAX_STRING_SIZE = 500;

const int MAX_WORD_SIZE = 20;

void readString(char string[]);

size_t myStrLen(char string[]);

int main ()
{
    char s[MAX_STRING_SIZE], d[MAX_WORD_SIZE];
    int counter = 0;

    readString(s);
    readString(d);

    size_t size1, size2;
    size1 = myStrLen(s);
    size2 = myStrLen(d);

    for (size_t i = 0; i < size2; ++i)
    {
        bool letterOccurs = false;
        for (size_t j = 0; j < size1; ++j)
        {
            if (d[i] == s[j])
            {
                letterOccurs = true;
            }
        }
        if (letterOccurs)
        {
            ++counter;
        }
    }

    std::cout << counter << std::endl;

    return 0;
}

void readString(char string[])
{
    std::cin >> string;
}

size_t myStrLen(char string[])
{
    size_t len = 0;

    while (string[len])
    {
        ++len;
    }

    return len;
}