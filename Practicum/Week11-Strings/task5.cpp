#include <iostream>

int readNames(char names[][50]);

size_t myStrLen(char array[]);

bool areStringsTheSame(char string1[], char string2[]);

void printString(char string[], size_t size);

int main ()
{
    char names[100][50];
    int numberOfNames = readNames(names);

    for (int i = 0; i < numberOfNames; ++i)
    {
        int counter = 1;
        if (names[i][0] != '#' && names[i][1] != '#')
        {
            for (int j = i+1; j < numberOfNames; ++j)
            {
                if (areStringsTheSame(names[i], names[j]))
                {
                    ++counter;
                    names[j][0] = '#';
                    names[j][1] = '#';
                }
            }
            if (counter > 1)
            {
                printString(names[i], myStrLen(names[i]));
                std::cout << counter << std::endl;
            }
        }
    }

    return 0;
}

int readNames(char names[][50])
{
    int i = 0;
    while (true)
    {
        std::cin >> names[i];
        if (myStrLen(names[i]) == 2 && names[i][0] == '#' && names[i][1] == '#')
        {
            break;
        }
        ++i;
    }
    return i;
}

size_t myStrLen(char word[])
{
    size_t len = 0;
    while (word[len])
    {
        ++len;
    }
    return len;
}

void printString(char string[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << string[i];
    }
    std::cout << " ";
}

bool areStringsTheSame(char string1[], char string2[])
{
    if (myStrLen(string1) != myStrLen(string2))
    {
        return false;
    }
    for (size_t i = 0; i < myStrLen(string1); ++i)
    {
        if (string1[i] != string2[i])
        {
            return false;
        }
    }
    return true;
}