#include <iostream>

int main ()
{
    int n, result, weight;

    std::cin >> n;
    std::cin >> result >> weight;

    int maxResult = result, minWeight = weight, winnerIndex = 1;

    for (int i = 2; i <= n; ++i)
    {
        std::cin >> result >> weight;
        if (result > maxResult || (result == maxResult && weight < minWeight))
        {
            maxResult = result;
            minWeight = weight;
            winnerIndex = i;
        }
    }

    std::cout << winnerIndex << std::endl;

    return 0;
}