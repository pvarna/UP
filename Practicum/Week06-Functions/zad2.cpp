#include <iostream>

void printFirstNNaturalNumbers (int number);

int main ()
{
    int n;

    std::cin >> n;

    printFirstNNaturalNumbers(n);

    return 0;
}

void printFirstNNaturalNumbers (int number)
{
    for (int i = 1; i <= number; ++i)
    {
        std::cout << i << " ";
    }
}