#include <iostream>

void printLetters();

int main ()
{
    printLetters();

    return 0;
}

void printLetters()
{
    int letterSize = 6;

    for (int i = 0; letterSize > 0; ++i)
    {
        for (int j = 0; j < i+1 && letterSize > 0; ++j)
        {
            char letter = 'A' + (6 - letterSize);
            std::cout << letter << " ";
            --letterSize;
        }
        std::cout << std::endl;
    }
}