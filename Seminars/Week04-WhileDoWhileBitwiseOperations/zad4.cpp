#include <iostream>

int main ()
{
    int number, sumDeviders = 0, i = 1;

    std::cin >> number;

    while(i < number)
    {
        if (number % i == 0)
        {
            sumDeviders += i;
        }

        ++i;
    }

    if (sumDeviders == number)
    {
        std::cout << "The number is perfect" << std::endl;
    }
    else
    {
        std::cout << "The number isn't perfect" << std::endl;
    }
    

    return 0;
}