#include <iostream>

const char* myStrStr(const char* where, const char* what);

size_t myStrLen(const char* text);

const char* removeVisoko(const char* text);

int main ()
{
    const char* str = "V bavisokozata na OON koqto e na visoko e otkrita vvisokounshna namesa. Trqbva nevisokozabano da suobshtim za sreshtata v 4 na vseki chovek ot otdela!";
    const char* visoko = "visoko";
    size_t size = myStrLen(str);
    char newStr[1000];
    int counter = 0;
    for (int i = 0; i < size; ++i)
    {
        bool isThisVisoko = false;
        bool isVisokoInAWord = false;
        if(str[i] == 'v')
        {
            isThisVisoko = true;
            for (int j = 0; j < 6; ++j)
            {
                if (str[i+j] != visoko[j])
                {
                    isThisVisoko = false;
                    break;
                }
            }
            if (isThisVisoko)
            {
                if ((str[i-1] >= 'a' && str[i-1] >= 'z') || (str[i+6] >= 'a' && str[i+6] >= 'z'))
                {
                    isVisokoInAWord = true;
                }
            }
            if (isVisokoInAWord)
            {
                i += 6;
            }
        }
        newStr[counter] = str[i];
        ++counter;
    }

    for (int i = 0; i < counter; ++i)
    {
        std::cout << newStr[i];
    }
    std::cout << std::endl;

    return 0;
}
size_t myStrLen(const char* text)
{
    size_t length = 0;
    while(text[length])
    {
        ++length;
    }
    return length;
}