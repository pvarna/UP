#include <iostream>

char * createString(int* size);

char * concatenateStrings(char* string1, char* string2, int size1, int size2);

int main ()
{
    int sizeFirstString = 10, sizeSecondString = 5;
    //char* firstString = createString(&sizeFirstString);
    char* firstString = new char[sizeFirstString] {'M', 'y', ' ', 'n', 'a', 'm', 'e', ' ', 'i', 's'};
    char* secondString = new char[sizeSecondString] {'P', 'e', 't', 'e', 'r'};

    char* concatenatedString = concatenateStrings(firstString, secondString, sizeFirstString, sizeSecondString);

    for (int i = 0; i < sizeFirstString+sizeSecondString; ++i)
    {
        std::cout << concatenatedString[i];
    }

    delete[] firstString;
    delete[] secondString;
    delete[] concatenatedString;

    return 0;
}

char * concatenateStrings(char* string1, char* string2, int size1, int size2)
{
    char* result = new char[size1+size2];
    int counter = 0;

    for (int i = 0; i < size1; ++i, ++counter)
    {
        result[counter] = string1[i];
    }
    for (int i = 0; i < size2; ++i, ++counter)
    {
        result[counter] = string2[i]; 
    }

    return result;

}

char * createString(int* size)
{
    char* array = new char[1000];
    *size = 0;

    do
    {
        std::cin >> array[*size];
    } while (array[*size++] != '\0');

    return array;
}