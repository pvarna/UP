#include <iostream>

void printRow(char letter, char current);

void printRowWrapper(char letter);

void printTriangle(char letter);

int main ()
{
    char ch;

    std::cin >> ch;

    printTriangle(ch);

    return 0;
}

void printRow (char letter, char current)
{
    if (current == letter+1)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << current << " ";
    printRow(letter, current+1);
}

void printRowWrapper(char letter)
{
    printRow(letter, 'A');
}

void printTriangle(char letter)
{
    if (letter == 'A'-1)
    {
        return;
    }
    printRowWrapper(letter);
    printTriangle(letter-1);
}