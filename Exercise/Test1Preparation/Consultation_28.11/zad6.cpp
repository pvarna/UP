#include <iostream>

bool isArmstrong (int number);

int main ()
{
    size_t size;
    int arr[100];

    do
    {
        std::cin >> size;

    } while (size < 5 || size > 100);
    
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    bool found = false;

    for (int i = 0; i < size; ++i)
    {
        if (isArmstrong(arr[i]))
        {
            std::cout << arr[i] << std::endl;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No Armstrong numbers!" << std::endl;
    }

    return 0;
}

bool isArmstrong (int number)
{
    int sum = 0;
    int temp = number;

    while (temp)
    {
        int digit = temp % 10;
        sum += digit*digit*digit;
        temp /= 10;
    }

    return (sum == number);
}