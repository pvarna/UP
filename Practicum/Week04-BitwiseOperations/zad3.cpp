#include <iostream>

int main()
{
    int number, res;

    std::cin >> number;

    res = (number<<1) + number + (number>>1); // 3.5 = 2^1 + 2^0 + 2^(-1)

    std::cout << res << std::endl;
    
    return 0;
}