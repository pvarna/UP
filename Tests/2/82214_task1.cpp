//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в програмирането 2020/21
// Контролно 2
// 2020-01-17
//
// Начален час: 10:00 ч.
// Име: Петър Станомиров Колев
// ФН: 82214
// Специалност: Компютърни науки
// Курс: 1
// Административна група: 4
// Използван компилатор: GCC
//

#include <iostream>

const int MAX_ARRAY_SIZE = 1000;

void print(int* array, size_t size, int counter);

bool isSorted(int* array, size_t size, int currentIndex, bool areEqual);

void insertInSorted(int* array, size_t size, int element);

int findPos(int* array, size_t size, int element, int currentIndex);

void moveElementsByOnePos(int* array, size_t size, int pos, int currentElement);

int main ()
{
    int numbers[MAX_ARRAY_SIZE] = {};
    int n, element;
    size_t size = 0;

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> element;
        insertInSorted(numbers, size, element);
        ++size;
    }

    std::cout << std::boolalpha << isSorted(numbers, size, 1, true) << std::endl;
    print(numbers, size, 0);

    return 0;
}

void print(int* array, size_t size, int counter)
{
    if (counter == size)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << array[0] << " ";
    ++counter;
    print(array+1, size, counter);
}

bool isSorted(int* array, size_t size, int currentIndex, bool areEqual)
{
    if (currentIndex == size && !areEqual)
    {
        return true;
    }

    if (array[currentIndex] != array[currentIndex-1])
    {
        areEqual = false;
    }

    if (array[currentIndex] < array[currentIndex-1])
    {
        return false;
    }
    ++currentIndex;
    return isSorted(array, size, currentIndex, areEqual);
}

void insertInSorted(int* array, size_t size, int element)
{
    if (size == 0)
    {
        array[0] = element;
    }
    else
    {
        int pos = findPos(array, size, element, 0);
        moveElementsByOnePos(array, size, pos, size);
        array[pos] = element;   
    }
}

int findPos(int* array, size_t size, int element, int currentIndex)
{
    if (currentIndex == size)
    {
        return currentIndex;
    }
    if (element < array[currentIndex])
    {
        return currentIndex;
    }
    ++currentIndex;
    return findPos(array, size, element, currentIndex);
}

void moveElementsByOnePos(int* array, size_t size, int pos, int currentElement)
{
    if (currentElement == pos)
    {
        return;
    }
    array[currentElement] = array[currentElement-1];
    --currentElement;
    moveElementsByOnePos(array, size, pos, currentElement);
}