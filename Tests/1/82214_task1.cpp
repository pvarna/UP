//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в програмирането 2020/21
// Контролно 1
// 2020-11-29
//
// Начален час: 09:00 ч.
// Име: Петър Станомиров Колев
// ФН: 82214
// Специалност: Компютърни науки
// Курс: 1
// Административна група: 4
// Използван компилатор: MinGW (GCC)
//

#include <iostream>
#include <cmath>

int binaryToDecimal (int number);

double decimalToBinary (int number);

int getNumberOfDigits (int number);

int main ()
{
    int a, b;
    double sum = 0;
    int aDecimal, bDecimal;
    std::cin >> a >> b;

    aDecimal = binaryToDecimal(a);
    bDecimal = binaryToDecimal(b);

    //std::cout << aDecimal << " " << bDecimal << std::endl;

    sum = aDecimal + bDecimal;

    if (getNumberOfDigits(decimalToBinary(sum)) < 5)
    {
        //std::cout << getNumberOfDigits(decimalToBinary(sum)) << std::endl;
        for (int i = 0; i < 5-getNumberOfDigits(decimalToBinary(sum)); ++i)
        {
            std::cout << "0";
        }
    }
    std::cout << decimalToBinary(sum) << std::endl;

    return 0;
}

int binaryToDecimal (int number)
{
    int base = 1;
    int temp = number;
    int decimalNumber = 0;
    while (temp)
    {
        int lastDigit = temp % 10;
        decimalNumber += lastDigit * base;
        base *= 2;
        temp /= 10;
    }

    return decimalNumber;
}

double decimalToBinary (int number)
{
    double exponent = 0;
    int temp = number;
    double binaryNumber = 0;
    while (temp)
    {
        int remainder = temp % 2;
        binaryNumber += remainder * pow (10.0, exponent);
        ++exponent;
        temp /= 2;
    }

    return binaryNumber;
}

int getNumberOfDigits (int number)
{
    int counter = 0;
    
    while (number)
    {
        int lastDigit = number % 10;
        ++counter;
        number /= 10;
    }

    return counter;
}