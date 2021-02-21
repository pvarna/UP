#include <iostream>
#include <cstring>

const int MAX_STRING_SIZE = 1000;

int main ()
{
    char* string = new(std::nothrow) char[MAX_STRING_SIZE];

    int i = 0;
    std::cin.get(string[i]);
    while (string[i] != '!')
    {
        ++i;
        std::cin.get(string[i]);
    }

    for (int j = 0; j < strlen(string)-1; ++j)
    {
        int counter = 1;
        if (string[j] != '!')
        {
            for (int k = j+1; k < strlen(string)-1; ++k)
            {
                if (string[j] == string[k])
                {
                    ++counter;
                    string[k] = '!';
                }
            }
            std::cout << "'" << string[j] << "' - " << counter << std::endl;
        }
    }

    delete[] string;
    return 0;
}