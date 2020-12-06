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

const int MAX_ARRAY_SIZE = 100;

const double EPS = 1.0/(1<<30);

size_t readSize ();

void readArray (double array[], size_t size);

bool isThereSameDifference (double array[], size_t size, int k, double m);

int main ()
{
    size_t n = readSize ();
    double numbers[MAX_ARRAY_SIZE] = {};

    readArray (numbers, n);

    double currentDifference = 0, maxDifference = 0;
    double maxK = 1;
    bool flag = false;
    for (int i = 1; i < n-1; ++i)
    {
        currentDifference = fabs(numbers[0] - numbers[0+i]);
        if (isThereSameDifference (numbers, n, i, currentDifference))
        {
            //std::cout << "zmiq" << std::endl;
            if (i > maxK)
            {
                maxK = i;
                maxDifference = currentDifference;
            }
            flag = true;
        }
    }
    if (flag)
    {
        std::cout << maxK << " " << maxDifference << std::endl;
    }
    else
    {
        std::cout << "No solution" << std::endl;
    }
    
    return 0;
}

size_t readSize ()
{
    size_t size;
    do
    {
        std::cout << "N = ";
        std::cin >> size;

    } while (size < 0 || size > 1000000);
    
    return size;
}

void readArray (double array[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cin >> array[i];
    }
}

bool isThereSameDifference (double array[], size_t size, int k, double m)
{
    for (int i = 1; i < size - k; ++i)
    {
        if (fabs((fabs(array[i] - array[i+k]) - m)) >= EPS)
        {
            //std::cout << i << " " << array[i] << " " << array[i+k] << " " << fabs(fabs(array[i] - array[i+k]) - m) << " " << m << std::endl;
            return false;
        }
        /*if (fabs(array[i] - array[i+k]) != m)
        {
            return false;
        }*/
    }

    return true;
}