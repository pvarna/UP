#include <iostream>

typedef double (*mainFunc) (double number, double percent);

double increase(double number, double percent)
{
    number += number*percent/100;
    return number;
}

double reduce(double number, double percent)
{
    number -= number*percent/100;
    return number;
}

double doCalculation(mainFunc fn, double number, double percent)
{
    return fn(number, percent);
}

int main ()
{
    size_t size;

    std::cin >> size;

    double* numbers = new(std::nothrow) double[size];

    for (int i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }

    double increasePercent, reducePercent;

    std::cin >> increasePercent >> reducePercent;

    for (int i = 0; i < size; ++i)
    {
        std::cout << doCalculation(increase, numbers[i], increasePercent) << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << doCalculation(reduce, numbers[i], reducePercent) << " ";
    }

    delete[] numbers;

    return 0;
}