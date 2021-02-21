#include <iostream>

int main ()
{
    double a, b;

    std::cin >> a >> b;

    if(a == 0)
    {
        if(b == 0) std::cout << "All numbers are solutions." << std::endl;
        else std::cout << "No solution." << std::endl;
    }
    else
    {
        std::cout << "There is one solution: " << -b/a << std::endl;
    }
    
    
    return 0;
}