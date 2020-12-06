#include <iostream>

const int MAX_SIZE_ARRAY = 1000;

int getLengthOfNumber (int number);

void saveDigitsOfNumberInArray (int arr[], size_t size, int number);

void reverseArray (int arr[], size_t size);

void swap (int &a, int &b);

void printArray (int arr[], size_t size);

int main ()
{
    int number;
    int digits[MAX_SIZE_ARRAY];

    std::cin >> number; 

    size_t size = getLengthOfNumber(number);

    saveDigitsOfNumberInArray(digits, size, number);

    printArray(digits, size);

    return 0;
}

int getLengthOfNumber (int number)
{
    int length = 0;
    while (number)
    {
        ++length;
        number /= 10;
    }

    return length;
}

void saveDigitsOfNumberInArray (int arr[], size_t size, int number)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = number % 10;
        number /= 10;
    }
    reverseArray(arr, size);
}

void swap (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void reverseArray (int arr[], size_t size)
{
    for (int i = 0; i < size/2; ++i)
    {
        swap (arr[i], arr[size-1-i]);
    }
}

void printArray (int arr[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}