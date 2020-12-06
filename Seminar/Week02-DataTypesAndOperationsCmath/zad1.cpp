#include <iostream>

int main ()
{
    int age;
    bool isAdult;

    std::cin >> age;

    isAdult = age >= 18 ? true : false;

    std::cout << std::boolalpha << isAdult << std::endl;

    return 0;
}