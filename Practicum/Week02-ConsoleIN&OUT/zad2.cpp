#include <iostream>

int main()
{
    int n;

    std::cin >> n;

    std::cout << "Full circles: " << n / 12 << std::endl;
    std::cout << "Clock arrow is at: " << n % 12 << std::endl;

    return 0;
}