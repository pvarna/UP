#include <iostream>
#include <cstring>

bool isPalindrom(const char* str, int counter, size_t originalSize, size_t currentSize);

bool isPalindromWrapper(const char* str, size_t size);

int main ()
{
    char str[30];

    std::cin >> str;

    if(isPalindromWrapper(str, strlen(str)))
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}

bool isPalindrom(const char* str, int counter, size_t originalSize, size_t currentSize)
{
    if (counter == originalSize/2)
    {
        return true;
    }

    if (*str != str[currentSize-1-counter])
    {
        return false;
    }

    ++counter;
    --currentSize;

    return isPalindrom(str+1, counter, originalSize, currentSize);
}

bool isPalindromWrapper(const char* str, size_t size)
{
    return isPalindrom(str, 0, size, size);
}