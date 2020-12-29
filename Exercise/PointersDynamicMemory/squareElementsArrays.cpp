#include <iostream>

int* squareElements (int begin, int end);

int main ()
{
    int* a = squareElements(1, 10);
    for(int i = 1; i < 10; ++i)
    {
        std::cout << *(a + i) << std::endl;
    }
    delete a;

    return 0;
}

int* squareElements (int begin, int end)
{
    int* ints = new int[end-begin];
    for (int i = begin; i < end; ++i)
    {
        ints[i] = i*i;
    }
    return ints;
}