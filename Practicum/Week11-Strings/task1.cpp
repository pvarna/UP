#include <iostream>

const int MAX_ARRAY_SIZE = 1000;

void readString(char word[]);

void getMostCommonLetter(char word[], size_t size, char* letter, int* numberOfTimes);

int main ()
{
    size_t l;
    char letter;
    int numberOfTimes;

    do
    {
        std::cin >> l;
    } while (l > MAX_ARRAY_SIZE);

    //const char* word = new(std::nothrow) char[l];
    char word[MAX_ARRAY_SIZE];

    readString(word);

    getMostCommonLetter(word, l, &letter, &numberOfTimes);

    std::cout << numberOfTimes << " " << letter << std::endl;

    //readString(word, l);

    //delete[] word;    

    return 0;
}
//void readString(const *char word)
void readString(char word[])
{
    /*for (size_t i = 0; i < size; ++i)
    {
        std::cin >> word[i];
    }*/

    std::cin >> word;
}

void getMostCommonLetter(char word[], size_t size, char* letter, int* numberOfTimes)
{
    *letter = word[0];
    *numberOfTimes = 1;
    for (size_t i = 0; i < size; ++i)
    {
        int currentMathes = 1;
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            for (size_t j = i+1; j < size; ++j)
            {
                if (word[j] == word[i])
                {
                    ++currentMathes;
                    word[j] = 'A';
                }
            }
            if (currentMathes > *numberOfTimes)
            {
                *numberOfTimes = currentMathes;
                *letter = word[i];
            }
        }
    }
}