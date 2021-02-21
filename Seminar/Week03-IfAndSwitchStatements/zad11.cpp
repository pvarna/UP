#include <iostream>

int main ()
{
    int month;

    std::cin >> month;

    if (month < 0 || month > 12) {
        std::cout << month << " Invalid user input!\n";
        return 1;
    }

    int days = 0;
    switch (month)
    {
    default:
        days += 1;
    case 4: case 6: case 9: case 11:
        days += 2;
    case 2:
        days += 28;
    }

    std::cout << days << std::endl;
    
    return 0;
}