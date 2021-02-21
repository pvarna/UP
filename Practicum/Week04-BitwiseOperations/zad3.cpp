#include <iostream>

int main()
{
    int number, res;

    std::cin >> number;

    res = (number << 1) + number + (number >> 1); // 3.5 = 2^1 + 2^0 + 2^(-1)

    std::cout << res << std::endl;
    
    return 0;
}

// n >> 2 -> n/4 = 0.25 * n
// n >> 1 -> n/2 = 0.50 * n
// n      ->     = 1.00 * n
// n << 1 ->     = 2.00 * n 
// n << 2 ->     = 4.00 * n

// 3.5 = 2 + 1 + 0.5 