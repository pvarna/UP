#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t myStrLen (char arr[]);

void lowerToUpper (char& ch);

void printStr (char str[], size_t size);

int main ()
{
    char str[MAX_ARRAY_SIZE];

    std::cin >> str;

    size_t size = myStrLen(str);

    printStr (str, size);

    for (int i = 0; i < size; ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            lowerToUpper(str[i]);
        }
    }

    printStr (str, size);

    return 0;
}

size_t myStrLen (char arr[])
{
    int counter = 0;
    for (int i = 0; arr[i] != '\0'; ++i)
    {
        ++counter;
    }

    return counter;
}

void lowerToUpper (char& ch)
{
    int difference = 'a'-'A';
    ch -= difference;
}

void printStr (char str[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << str[i];
    }

    std::cout << std::endl;
}