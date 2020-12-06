#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t myStrLen (char arr[]);

void myStrCpy (char arr1[], char arr2[]);

int main ()
{
    char str1[MAX_ARRAY_SIZE] = {};
    char str2[MAX_ARRAY_SIZE] = {};

    std::cin >> str1;
    std::cin >> str2;

    //std::cout << myStrLen(str1) << std::endl;
    //std::cout << myStrLen(str2) << std::endl;

    myStrCpy (str1, str2);

    size_t size1 = myStrLen (str1);

    for (int i = 0; i < size1; ++i)
    {
        std::cout << str1[i] << " ";
    }

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

void myStrCpy (char arr1[], char arr2[])
{
    size_t size2 = myStrLen (arr2);

    for (int i = 0; i < size2; ++i)
    {
        arr1[i] = arr2[i];
    }
}