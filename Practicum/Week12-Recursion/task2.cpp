#include <iostream>

size_t myStrLen (const char* str, size_t counter);

size_t myStrLenWrapper (const char* str);

int main ()
{
    char str[100];

    std::cin >> str; 

    std::cout << myStrLenWrapper(str) << std::endl;

    return 0;
}

size_t myStrLen (const char* str, size_t counter)
{
    if (!(*str))
    {
        return counter;
    }
    ++counter;
    return myStrLen(str+1, counter);
}

size_t myStrLenWrapper (const char* str)
{
    return myStrLen(str, 0);
}