#include <iostream>

void generateStr(int n);

void findAnswer(int n, char* str, int current);

int main ()
{
    int n;

    std::cin >> n;

    generateStr(n);

}

void generateStr(int n)
{
    char str[100];
    
    str[0] = '0';
    findAnswer(n, str, 1);

    str[0] = '1';
    findAnswer(n, str, 1);
}

void findAnswer(int n, char* str, int current)
{
    if (current == n)
    {
        str[n] = '\0';
        std::cout << str << std::endl;
        return;
    }
    if (str[current-1] == '1')
    {
        str[current] = '0';
        findAnswer(n, str, current+1);
    }
    else
    {
        str[current] = '0';
        findAnswer(n, str, current+1);
        str[current] = '1';
        findAnswer(n, str, current+1);
    }
    
}