#include <iostream>
#include <cstring>

int main ()
{
    char* string = new(std::nothrow) char[1000];

    int i = 0;
    char ch;
    do
    {
        std::cin.get(ch);
    } while (ch == ' ');

    string[i] = ch;

    while (string[i] != '\n')
    {
        std::cin.get(ch);
        if (ch != ' ' || (ch == ' ' && string[i] != ' '))
        {
            ++i;
            string[i] = ch;
        }
    }

    for (int j = 0; j < strlen(string-1); ++j)
    {
        std::cout << string[j];
    }
    std::cout << std::endl;

    delete[] string;

    return 0;
}