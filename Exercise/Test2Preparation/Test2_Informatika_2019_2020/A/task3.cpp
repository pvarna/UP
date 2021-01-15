#include <iostream>
#include <cstring>

char* rleEncode(const char* text);

int main ()
{
    const char* text = "aaaaaaaaabcdddddaaaaaaabcccccadddd";

    char* newText = rleEncode(text);

    std::cout << newText << std::endl;

    delete[] newText;

    return 0;
}

char* rleEncode(const char* text)
{
    size_t size = strlen(text);
    size_t compressedSize = size;

    for (int i = 1; i < size; ++i)
    {
        if (text[i] == text[i-1])
        {
            int counter = 2;
            while (text[i+counter-1] == text[i])
            {
                ++counter;
            }
            if (counter >= 4)
            {
                compressedSize = compressedSize - counter + 4;
            }
            i += (counter-2);
        }
    }

    char* newText = new(std::nothrow) char[compressedSize+1];
    int currentIndex = 0;

    for (int i = 1; i < size; ++i)
    {
        if (text[i] != text[i-1])
        {
            newText[currentIndex] = text[i-1];
            ++currentIndex;
        }
        else
        {
            int counter = 2;
            while (text[i+counter-1] == text[i])
            {
                ++counter;
            }
            if (counter >= 4)
            {
                newText[currentIndex] = '(';
                newText[currentIndex+1] = '0' + counter;
                newText[currentIndex+2] = text[i];
                newText[currentIndex+3] = ')';
                currentIndex += 4;
                i += (counter-1);
            }
            else
            {
                newText[currentIndex] = text[i-1];
                ++currentIndex;
            }           
        }
    }
    newText[currentIndex] = '\0';

    return newText;
}