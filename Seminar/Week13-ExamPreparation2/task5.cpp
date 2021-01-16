#include <iostream>
#include <cstring>

char* toEnd(char arr[], char symbols[]);

int main ()
{
    char firstStr[1000], symbols[4];

    std::cin.getline(firstStr, 1000);

    std::cin >> symbols;

    char* newStr = toEnd(firstStr, symbols);

    std::cout << newStr << std::endl;

    delete[] newStr;

    return 0;
}

char* toEnd(char arr[], char symbols[])
{
    size_t size = strlen(arr);
    char* newStr = new(std::nothrow) char[size+1];
    int counter = 0;

    for (int i = 0; i < size; ++i)
    {
        bool match = false;
        for (int j = 0; j < 3; ++j)
        {
            if (arr[i] == symbols[j])
            {
                match = true;
                break;
            }
        }
        if (!match)
        {
            newStr[counter++] = arr[i];
        }
    }

    for (int i = 0; i < size; ++i)
    {
        bool match = false;
        for (int j = 0; j < 3; ++j)
        {
            if (arr[i] == symbols[j])
            {
                match = true;
                break;
            }
        }
        if (match)
        {
            newStr[counter++] = arr[i];
        }
    }
    newStr[counter] = '\0';

    return newStr;
}