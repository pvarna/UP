#include <iostream>

int main ()
{
    int number;
    bool isTrue;

    std::cin >> number;

    isTrue = (number >10 && number % 5 == 0) ? true : false;

    std::cout << std::boolalpha << isTrue << std::endl;

    return 0;
}