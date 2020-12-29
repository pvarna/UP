#include <iostream>

void print(int* array, size_t size);

void print(const char* text);

int main ()
{
    int numbers[5] = {1, 2, 3, 4, 5};

    print(numbers, 5);
    print("Peter Kolev");

    return 0;
}

void print(int* array, size_t size)
{
    if (size == 0)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << *array << " ";
    print(array+1, size-1);
}

void print(const char* text)
{
    if(!(*text))
    {
        return;
    }
    std::cout << *text;
    print(text+1);
}