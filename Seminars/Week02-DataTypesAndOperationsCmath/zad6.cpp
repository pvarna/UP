#include <iostream>

int main ()
{
    int number;
    bool isTrue;

    std::cin >> number;

    isTrue = (number > 0 && (number % 7 == 0 || number % 9 == 0)) ? true : false;

    std::cout << std::boolalpha << isTrue << std::endl;

    return 0;
}