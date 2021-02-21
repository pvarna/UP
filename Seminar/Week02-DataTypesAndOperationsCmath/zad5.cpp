#include <iostream>

int main ()
{
    int number;
    bool isTrue;

    std::cin >> number;

    isTrue = (number > 100 || number % 2 == 0) ? true : false;

    std::cout << std::boolalpha << isTrue << std::endl;

    return 0;
}