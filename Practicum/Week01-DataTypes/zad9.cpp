#include <iostream>

int main ()
{
    char ch;

    std::cin >> ch;

    ch += int('a'-'A');

    std::cout << ch << std::endl;

    return 0;
}

