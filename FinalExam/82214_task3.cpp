//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Практически изпит - задачи
// 2021-02-08
//
// Име: Петър Станомиров Колев
// ФН: 82214
// Специалност: Компютърни науки, 1 поток
// Курс: 1
// Административна група: 4
// Използван компилатор: GCC
//

#include <iostream>

int* allocateArray(int n);

int** allocate2DArray(int rows, int columns);

void clearMemory2DArray(int** array, int rows);

void findBestWayToPutToysInBoxes(int* boxes, int k, int* toys, int n, int currentToy, int* freeSpaceEachBox, int** minBoxesToys, int* countMinToysEachBox, int** currentBoxesToys, int* countCurrentToysEachBox, int& minToysLeft, int currentToysLeft);

int main ()
{
    int k;

    std::cin >> k;

    int* boxes = allocateArray(k);
    if(!boxes)
    {
        return 1;
    }

    for (int i = 0; i < k; ++i)
    {
        std::cin >> boxes[i];
    }

    int n;

    std::cin >> n;

    int* toys = allocateArray(n);
    if (!toys)
    {
        return 1;
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> toys[i];
    }

    int* freeSpaceEachBox = allocateArray(k);
    if (!freeSpaceEachBox)
    {
        return 1;
    }
    for (int i = 0; i < k; ++i)
    {
        freeSpaceEachBox[i] = boxes[i];
    }

    int** minBoxesToys = allocate2DArray(k, n);
    if (!minBoxesToys)
    {
        return 1;
    }

    int* countMinToysEachBox = allocateArray(k);
    for (int i = 0; i < k; ++i)
    {
        countMinToysEachBox[i] = 0;
    }

    int** currentBoxesToys = allocate2DArray(k, n);
    if(!currentBoxesToys)
    {
        return 1;
    }

    int* countCurrentToysEachBox = allocateArray(k);
    for (int i = 0; i < k; ++i)
    {
        countCurrentToysEachBox[i] = 0;
    }

    int minToysLeft = n;

    findBestWayToPutToysInBoxes(boxes, k, toys, n, 0, freeSpaceEachBox, minBoxesToys, countMinToysEachBox, currentBoxesToys, countCurrentToysEachBox, minToysLeft, n);

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < countMinToysEachBox[i]; ++j)
        {
            std::cout << minBoxesToys[i][j] << " ";
        }
        if (countMinToysEachBox[i] == 0)
        {
            std::cout << -1 << std::endl;
        }
    }

    delete[] boxes;
    delete[] toys;
    delete[] freeSpaceEachBox;
    clearMemory2DArray(minBoxesToys, k);
    delete[] countMinToysEachBox;
    clearMemory2DArray(currentBoxesToys, k);
    delete[] countCurrentToysEachBox;

    return 0;
}

int* allocateArray(int n)
{
    int* array = new(std::nothrow) int[n];
    if (!array)
    {
        delete[] array;
        std::cout << "Memory problem!" << std::endl;
        return nullptr;
    }

    return array;
}

void findBestWayToPutToysInBoxes(int* boxes, int k, int* toys, int n, int currentToy, int* freeSpaceEachBox, int** minBoxesToys, int* countMinToysEachBox, int** currentBoxesToys, int* countCurrentToysEachBox, int& minToysLeft, int currentToysLeft)
{
    if (currentToysLeft < minToysLeft)
    {
        minToysLeft = currentToysLeft;
        for (int i = 0; i < k; ++i)
        {
            countMinToysEachBox[i] = countCurrentToysEachBox[i];
        }
        for (int i = 0; i < k; ++i)
        {
            for (int j = 0; j < countCurrentToysEachBox[i]; ++j)
            {
                minBoxesToys[i][j] = currentBoxesToys[i][j];
            }
        }
    }
    if (currentToy == n)
    {
        return;
    }
    if (currentToysLeft == 0)
    {
        return;
    }

    for (int i = 0; i < k; ++i)
    {
        if (toys[currentToy] <= freeSpaceEachBox[i])
        {
            currentBoxesToys[i][countCurrentToysEachBox[i]] = currentToy+1;
            ++countCurrentToysEachBox[i];
            freeSpaceEachBox[i] -= toys[currentToy];
            findBestWayToPutToysInBoxes(boxes, k, toys, n, currentToy+1, freeSpaceEachBox, minBoxesToys, countCurrentToysEachBox, currentBoxesToys, countCurrentToysEachBox, minToysLeft, currentToysLeft-1);
            freeSpaceEachBox[i] += toys[currentToy];
            --countCurrentToysEachBox[i];

        }
    }
}

int** allocate2DArray(int rows, int columns)
{
    int** array = new(std::nothrow) int*[rows];
    if (!array)
    {
        delete[] array;
        std::cout << "Memory problem!" << std::endl;
        return nullptr;
    }

    for (int i = 0; i < rows; ++i)
    {
        array[i] = new(std::nothrow) int[columns];
        if (!array[i])
        {
            clearMemory2DArray(array, i+1);
            std::cout << "Memory problem!" << std::endl;
            return nullptr;
        }
    }

    return array;
}

void clearMemory2DArray(int** array, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
}