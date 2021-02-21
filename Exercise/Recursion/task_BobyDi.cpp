#include <iostream>
#include <cstring>

bool doAllSymbolsFromHereOccureThere(const char* here, const char* there);

int main ()
{
    const char* str1 = "goodbook";
    const char* str2 = "gbkod";

    if (doAllSymbolsFromHereOccureThere(str1, str2))
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}

bool doAllSymbolsFromHereOccureThere(const char* here, const char* there)
{
    if (*here == '\0')
    {
        return true;
    }
    const char* occurrence = strchr(there, *here);
    if (occurrence == nullptr)
    {
        return false;
    }
    return doAllSymbolsFromHereOccureThere(here+1, there);
}