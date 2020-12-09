#include <iostream>

int main ()
{
    size_t size;
    do
    {
        std::cin >> size;

    } while (size < 5 || size > 1006);
    
    int arr[1006];

    for (int i = 1; i <= size; ++i)
    {
        std::cin >> arr[i];
    }

    int sum = 0;
    
    int first = 1, second = 1, third = first + second;

    sum += arr[first] + arr[second];

    while (third <= size)
    {
        first = second;
        second = third;
        sum += arr[third];
        third = first + second;
    }

    std::cout << "sum = " << sum << std::endl;
    return 0;
}