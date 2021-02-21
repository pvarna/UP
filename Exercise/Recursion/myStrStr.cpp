#include <iostream>

bool prefix(const char* text, const char* word); // Check if a string is prefix of another string

const char* myStrStr(const char* where, const char* what); // Check if a string is a part of another string

int main ()
{
    const char* text = "My name is Peter Kolev";
    const char* word = "Peter";

    std::cout << myStrStr(text, word) << std::endl;
    return 0;
}

bool prefix(const char* text, const char* word)
{
    if (!(*word))
    {
        return true;
    }
    if (!(*text))
    {
        return false;
    }
    return *word == *text && prefix(text+1, word+1);
}

const char* myStrStr(const char* where, const char* what)
{
    if(!(*where))
    {
        return nullptr;
    }
    if(prefix(where, what))
    {
        return where;
    }
    return myStrStr(where+1, what);
}