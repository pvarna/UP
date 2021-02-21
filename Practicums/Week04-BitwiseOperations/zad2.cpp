#include <iostream>

int main ()
{
    int num1, num2;

    std::cin >> num1 >> num2;

    if ((num1 ^ num2) > 0)
    {
        std::cout << "false" << std::endl;
    }
    else
    {
        std::cout << "true" << std::endl;
    }

    return 0;
}

/*
    0...    1...
   ^       ^
    0...    1...
    ----    ----
    0...    0... ---> same

    0...
   ^
    1...
    ----
    1... ---> different
*/