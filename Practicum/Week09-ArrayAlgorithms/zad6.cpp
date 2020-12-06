#include <iostream>

const int MAX_ARRAY_SIZE = 20;

int main ()
{
    int n;
    char letter;
    char password[20];

    std::cin >> n;

    int number = 0;
    for (int i = 0; i < 2*n-1; i+=2)
    {
        std::cin >> letter;
        password[i] = letter;
        if (i != 2*n-2)
        {
            password[i+1] = '0' + number;
        }
        ++number;
    }

    for (int i = 0; i < 2*n-1; ++i)
    {
        std::cout << password[i];
    }

    std::cout << std::endl;

    return 0;
}