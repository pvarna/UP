#include <iostream>
#include <cstring>

char* rleEncode(const char* text);

int getCountOfDigits (int number, int counter);

int main ()
{
    const char* text = "aaaaaaaaaaaaaaabcddddddaaaaaaabcccccaddddddddddddddddddddddddddddd";

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
                int digits = getCountOfDigits(counter, 0);
                compressedSize = compressedSize - counter + 3 + digits;
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
                int digits = getCountOfDigits(counter, 0);
                int tempCounter = counter;
                for (int i = digits; i >= 1; --i)
                {
                    newText[currentIndex+i] = '0' + (tempCounter%10);
                    tempCounter /= 10;
                }
                //newText[currentIndex+1] = '0' + counter;
                newText[currentIndex+digits+1] = text[i];
                
                newText[currentIndex+digits+2] = ')';
                currentIndex += (3+digits);
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

int getCountOfDigits (int number, int counter)
{
    if (number == 0)
    {
        return counter;
    }
    
    ++counter;

    return getCountOfDigits(number/10, counter);
}