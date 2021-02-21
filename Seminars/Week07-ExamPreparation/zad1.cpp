#include <iostream>

bool isSumOfDigitsDevidedByFive (int n);

int main ()
{
    int n;

    std::cin >> n;
    
    std::cout << std::boolalpha << isSumOfDigitsDevidedByFive(n) << std::endl;

    return 0;
}

bool isSumOfDigitsDevidedByFive (int n)
{
    int temp = n, sum = 0;
    while (temp)
    {
        int lastDigit = temp % 10;
        sum += lastDigit;
        temp /= 10;
    }

    return (sum % 5 == 0) ? true : false;
}