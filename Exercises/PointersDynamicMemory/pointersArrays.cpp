#include <iostream>

int main ()
{
    int array[3];
    array[0] = 10;
    array[1] = 20;
    array[2] = 30;

    int *pArray;
    pArray = array;

    std::cout << *pArray << std::endl;
    ++pArray;
    std::cout << *pArray << std::endl;
    ++pArray;
    std::cout << *pArray << std::endl;

    return 0;
}