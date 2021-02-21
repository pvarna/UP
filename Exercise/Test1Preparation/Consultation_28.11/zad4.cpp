#include <iostream>

int main ()
{
    char str[100];
    size_t size;

    std::cin >> size;

    for (int i = 0; i < size; ++i)
    {
        std::cin >> str[i];
    }

    int limit = size / 2;
    bool isPalindrome = true;
    for (int i = 0; i < limit; ++i)
    {
        if (str[i] != str[size-1-i])
        {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}