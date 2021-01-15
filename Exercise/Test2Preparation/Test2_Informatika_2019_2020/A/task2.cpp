#include <iostream>

int getCountOfDigits (int number, int counter);

bool checkResult (int longer, int shorter);

int main ()
{
    int number1, number2;

    std::cin >> number1 >> number2;

    bool isTrue;
    int size1 = getCountOfDigits(number1, 0);
    int size2 = getCountOfDigits(number2, 0);
    if (size1 > size2)
    {
        isTrue = checkResult(number1, number2);
    }
    else
    {
        isTrue = checkResult(number2, number1);
    }
    
    if (isTrue)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    
    

    return 0;
}

int getCountOfDigits (int number, int counter)
{
    if (number == 0)
    {
        return counter;
    }
    
    ++counter;

    return getCountOfDigits(number/10, counter);
}

bool checkResult (int longer, int shorter)
{
    if (shorter == 0)
    {
        return true;
    }
    if (longer == 0)
    {
        return false;
    }

    if (longer % 10 == shorter % 10)
    {
        shorter /= 10;
    }
    return checkResult(longer/10, shorter);
}