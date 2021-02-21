#include <iostream>

typedef void (*sort) (int* numbers, int n);

void printArray(int* numbers, int n);

void bubbleSort(int* numbers, int n);

void insertInSorted(int* numbers, int n, int x);

void insertionSort(int* numbers, int n);

void merge(int* numbers, int l, int m, int r);

void mergeSort(int* numbers, int l, int r);

void mergeSort(int* numbers, int n);

void sortNumbers(sort fn, int* numbers, int n);

int main ()
{
    int n;
    int numbersBubble[100], numbersInsertion[100], numbersMerge[100];

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbersBubble[i];
        numbersInsertion[i] = numbersBubble[i];
        numbersMerge[i] = numbersBubble[i];
    }

    sortNumbers(bubbleSort, numbersBubble, n);
    std::cout << "Bubble sort: ";
    printArray(numbersBubble, n);

    sortNumbers(insertionSort, numbersInsertion, n);
    std::cout << "Insertion sort: ";
    printArray(numbersInsertion, n);

    sortNumbers(mergeSort, numbersMerge, n);
    std::cout << "Merge sort: ";
    printArray(numbersMerge, n);

    return 0;
}

void printArray(int* numbers, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

void bubbleSort(int* numbers, int n)
{
    bool changed = false;
    int end = 0;
    do
    {
        changed = false;
        for (int i = n-1; i > end; --i)
        {
            if (numbers[i] < numbers[i-1])
            {
                int temp = numbers[i];
                numbers[i] = numbers[i-1];
                numbers[i-1] = temp;
                changed = true;
            }
        }
        ++end;
    } while (changed);   
}

void insertInSorted(int* numbers, int n, int x)
{
    int index = n;
    for (int i = 0; i < n; ++i)
    {
        if (numbers[i] > x)
        {
            index = i;
            break;
        }
    }
    for (int i = n-1; i >= index; --i)
    {
        numbers[i+1] = numbers[i];
    }
    numbers[index] = x;
}

void insertionSort(int* numbers, int n)
{
    for (int i = 1; i < n; ++i)
    {
        insertInSorted(numbers, i, numbers[i]);
    }
}

void merge(int* numbers, int l, int m, int r)
{
    int size1 = m - l + 1;
    int size2 = r - m;

    int leftArray[100], rightArray[100];
    for (int i = 0; i < size1; ++i)
    {
        leftArray[i] = numbers[l+i];
    }
    for (int i = 0; i < size2; ++i)
    {
        rightArray[i] = numbers[m+1+i];
    }

    int i = 0, j = 0, k = l;

    while (i < size1 && j < size2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            numbers[k] = leftArray[i];
            ++i;
        }
        else
        {
            numbers[k] = rightArray[j];\
            ++j;
        }
        ++k;
    }

    while (i < size1)
    {
        numbers[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < size2)
    {
        numbers[k] = rightArray[j];
        ++j;
        ++k;
    }
}

void mergeSort(int* numbers, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int m = (l + r - 1) / 2;
    mergeSort(numbers, l, m);
    mergeSort(numbers, m+1, r);
    merge(numbers, l, m, r);
}

void mergeSort(int* numbers, int n)
{
    mergeSort(numbers, 0, n-1);
}

void sortNumbers(sort fn, int* numbers, int n)
{
    fn(numbers, n);
}