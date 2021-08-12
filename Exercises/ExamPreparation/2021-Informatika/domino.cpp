#include <iostream>

struct Domino
{
    int left;
    int right;
};

void findLongestRowOfDominos(Domino* domino, int n, int& maxCount, Domino* maxRow, int currentCount, Domino* currentRow, int* usedDominos);

int main ()
{
    int n;

    std::cin >> n;

    Domino* domino = new(std::nothrow) Domino[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> domino[i].left >> domino[i].right;
    }

    Domino* currentRow = new(std::nothrow) Domino[n];
    Domino* maxRow = new(std::nothrow) Domino[n];
    int* usedDominos = new(std::nothrow) int[n];
    int maxCount = 1;
    for (int i = 0; i < n; ++i)
    {
        currentRow[0].left = domino[i].left;
        currentRow[0].right = domino[i].right;
        usedDominos[0] = i;
        findLongestRowOfDominos(domino, n, maxCount, maxRow, 1, currentRow, usedDominos);
        currentRow[0].left = domino[i].right;
        currentRow[0].right = domino[i].left;
        usedDominos[0] = i;
        findLongestRowOfDominos(domino, n, maxCount, maxRow, 1, currentRow, usedDominos);
    }

    for (int i = 0; i < maxCount; ++i)
    {
        std::cout << maxRow[i].left << "-" << maxRow[i].right << " ";
    }
    std::cout << std::endl;

    delete[] domino;
    delete[] currentRow;
    delete[] maxRow;
    delete[] usedDominos;

    return 0;
}

void findLongestRowOfDominos(Domino* domino, int n, int& maxCount, Domino* maxRow, int currentCount, Domino* currentRow, int* usedDominos)
{
    if (currentCount > n)
    {
        return;
    }

    if (currentCount > maxCount)
    {
        maxCount = currentCount;
        for (int i = 0; i < currentCount; ++i)
        {
            maxRow[i] = currentRow[i];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        bool alreadyUsed = false;
        for (int j = 0; j < currentCount; ++j)
        {
            if (i == usedDominos[j])
            {
                alreadyUsed = true;
                break;
            }
        }
        if (!alreadyUsed)
        {
            if (currentRow[currentCount-1].right == domino[i].left)
            {
                currentRow[currentCount].left = domino[i].left;
                currentRow[currentCount].right = domino[i].right;
                usedDominos[currentCount] = i;
                findLongestRowOfDominos(domino, n, maxCount, maxRow, currentCount+1, currentRow, usedDominos);
            }
            if (currentRow[currentCount-1].right == domino[i].right)
            {
                currentRow[currentCount].left = domino[i].right;
                currentRow[currentCount].right = domino[i].left;
                usedDominos[currentCount] = i;
                findLongestRowOfDominos(domino, n, maxCount, maxRow, currentCount+1, currentRow, usedDominos);
            }
        }
    }
}