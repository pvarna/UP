#include <iostream>

int main ()
{
    int facultyNumber;
    bool isEven;

    std::cin >> facultyNumber;

    isEven = facultyNumber % 2 == 0 ? true : false;

    std::cout << std::boolalpha << isEven << std::endl;

    return 0;
}