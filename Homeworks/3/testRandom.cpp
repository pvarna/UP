#include <iostream>

void swapElementsInArray(double* array, int index1, int index2);

void swapRowsIn2DArray(int** array, int row1, int row2);

void sortTasks(int ** tasks, double* priority, size_t size);

int minElement(double* array, size_t size);

int main ()
{
    int tasksCount, remainingDays;

    std::cin >> tasksCount;

    int ** tasks = new(std::nothrow) int*[tasksCount];
    double * pointsPerMinute = new(std::nothrow) double[tasksCount];
    for (int i = 0; i < tasksCount; ++i)
    {
        tasks[i] = new(std::nothrow) int[3];
    }

    for (int i = 0; i < tasksCount; ++i)
    {
        std::cin >> tasks[i][0] >> tasks[i][1] >> tasks[i][2];
        pointsPerMinute[i] = (double)tasks[i][2] / (double)tasks[i][1];
    }

    std::cin >> remainingDays;

    int * minutesPerDay = new(std::nothrow) int[remainingDays];

    for (int i = 0; i < remainingDays; ++i)
    {
        std::cin >> minutesPerDay[i];
    }

    std::cout << std::endl;
    for (int i = 0; i < tasksCount; ++i)
    {
        std::cout << tasks[i][0] << " " << tasks[i][1] << " " << tasks[i][2] << " " << pointsPerMinute[i] << std::endl;
    }

    sortTasks(tasks, pointsPerMinute, tasksCount);
    std::cout << std::endl;
    for (int i = 0; i < tasksCount; ++i)
    {
        std::cout << tasks[i][0] << " " << tasks[i][1] << " " << tasks[i][2] << " " << pointsPerMinute[i] << std::endl;
    }

    for (int i = 0; i < tasksCount; ++i)
    {
        delete[] tasks[i];
    }
    delete[] tasks;
    delete[] pointsPerMinute;
    delete[] minutesPerDay;

    return 0;
}

void swapElementsInArray(double* array, int index1, int index2)
{
    double temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void swapRows(int** array, int row1, int row2)
{
    int* temp = array[row1];
    array[row1] = array[row2];
    array[row2] = temp;
}

int minElement(double* array, size_t size)
{
    int min = 0;
    for (int i = 1; i < size; ++i)
    {
        if (array[i] < array[min])
        {
            min = i;
        }
    }

    return min;
}

void sortTasks(int** tasks, double* priority, size_t size)
{
    for (int i = 0; i < size-1; ++i)
    {
        int minIndex = minElement(priority+i, size-i) + i;
        swapRows(tasks, i, minIndex);
    }
}