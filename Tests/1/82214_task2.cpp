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

int countOfDeviders (int number);

bool isPrime (int number);

int main ()
{
    int a, b, counter = 0;

    do
    {
        std::cin >> a >> b;

    } while (a < 1 || b < 1 || a > b);
    

    for (int i = a; i <= b; ++i)
    {
        if (isPrime(countOfDeviders(i)))
        {
            //std::cout << i << " ";
            ++counter;
        }
    }
    //std::cout << std::endl;
    std::cout << counter << std::endl;

    return 0;
}

int countOfDeviders (int number)
{
    int counter = 0;
    for (int i = 2; i <= number/2; ++i)
    {
        if (number % i == 0)
        {
            ++counter;
        }
    }
    
    return counter;
}

bool isPrime (int number)
{
    if (number == 0 || number == 1)
    {
        return false;
    }
    int counter = 0;
    for (int i = 2; i <= number/2; ++i)
    {
        if (number % i == 0)
        {
            ++counter;
        }
    }
    if (counter == 0)
    {
        return true;
    }
    return false;
}