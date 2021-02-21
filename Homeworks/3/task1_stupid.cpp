#include <iostream>
#include <limits>

// reads an int and validates if the input is a number and if it is bigger than 0
int readIntBiggerThan0();

// reads a new row for the 2D array of tasks
// validates if the minutes and the points are bigger than 0
// validates if the index is already used
void readNewRow(int ** array, int index);

// allocates memory for a 2D array
int ** allocate2DArray(size_t rows, size_t columns);

// allocates memory for a double array
double* allocateDoubleArray(size_t size);

// allocates memory for a int array
int* allocateIntArray(size_t size);

// clears the memory of a 2D array
void clear2DArray(int ** array, size_t rows);

// swaps two doubles
void swap(double* a, double* b);

// swaps two rows of a 2D array
void swapRows(int** array, int row1, int row2);

// sorts the tasks by points per minute
void sortTasks(int ** tasks, double* priority, size_t size);

// returns the index of the biggest element in an array
// helper function for the 'sortTasks' function
int maxElement(double* array, size_t size);

int main ()
{
    int tasksCount, remainingDays, availableTime = 0;

    tasksCount = readIntBiggerThan0();

    // allocating memory for the arrays
    int ** tasks = allocate2DArray(tasksCount, 3);
    double * pointsPerMinute = allocateDoubleArray(tasksCount);

    for (int i = 0; i < tasksCount; ++i)
    {
        readNewRow(tasks, i);
        pointsPerMinute[i] = (double)tasks[i][2] / (double)tasks[i][1]; // calculating points per minute for each task
    }

    remainingDays = readIntBiggerThan0();

    int * minutesPerDay = allocateIntArray(remainingDays);

    for (int i = 0; i < remainingDays; ++i)
    {
        minutesPerDay[i] = readIntBiggerThan0();
        availableTime += minutesPerDay[i];
    }

    sortTasks(tasks, pointsPerMinute, tasksCount);

    std::cout << "zmiqqqq" << std::endl;

    for (int i = 0; i < tasksCount; ++i)
    {
        std::cout << tasks[i][0] << " " << tasks[i][1] << " " << tasks[i][2] << " " << pointsPerMinute[i] << std::endl;
    }

    int * indexesOfTasks = allocateIntArray(tasksCount);
    int maxCountCompletedTasks = 0;
    int minRemainingTime = availableTime;
    int maxCollectedPoints = 0;
    for (int i = 0; i < tasksCount; ++i)
    {
        /*if (maxCountCompletedTasks > tasksCount - i)
        {
            break;
        }*/
        /*if (minRemainingTime == 0)
        {
            break;
        }*/
        // searching for the most optimized sequence of tasks
        // checking the shortest remaining time 
        int currentRemainingTime = availableTime;
        int currentCountCompletedTasks = 0;
        int currentCollectedPoints = 0;
        int * currentIndexes = allocateIntArray(tasksCount-i);
        for (int j = i; j < tasksCount; ++j)
        {
            if (currentRemainingTime >= tasks[j][1])
            {
                currentRemainingTime -= tasks[j][1];
                currentIndexes[currentCountCompletedTasks] = tasks[j][0];
                ++currentCountCompletedTasks;
                currentCollectedPoints += tasks[j][2];
            }
        }
        /*if (currentCountCompletedTasks > maxCountCompletedTasks)
        {
            maxCollectedPoints = currentCollectedPoints;
            maxCountCompletedTasks = currentCountCompletedTasks;
            minRemainingTime = currentRemainingTime;
            for (int k = 0; k < currentCountCompletedTasks; ++k)
            {
                indexesOfTasks[k] = currentIndexes[k];
            }
        }*/
        /*if (currentRemainingTime < minRemainingTime)
        {
            maxCollectedPoints = currentCollectedPoints;
            maxCountCompletedTasks = currentCountCompletedTasks;
            minRemainingTime = currentRemainingTime;
            for (int k = 0; k < currentCountCompletedTasks; ++k)
            {
                indexesOfTasks[k] = currentIndexes[k];
            }
        }*/
        if (currentCollectedPoints > maxCollectedPoints)
        {
            maxCollectedPoints = currentCollectedPoints;
            maxCountCompletedTasks = currentCountCompletedTasks;
            minRemainingTime = currentRemainingTime;
            for (int k = 0; k < currentCountCompletedTasks; ++k)
            {
                indexesOfTasks[k] = currentIndexes[k];
            }
        }
        delete[] currentIndexes;
    }
    if (maxCountCompletedTasks == 0)
    {
        std::cout << "There is no time for any tasks" << std::endl;
    }
    else
    {
        std::cout << "Tasks: " << indexesOfTasks[0];
        for (int i = 1; i < maxCountCompletedTasks; ++i)
        {
            std::cout << ", " << indexesOfTasks[i];
        }
        std::cout << std::endl;
        std::cout << "Time remaining: " << minRemainingTime / 60 << ":" << minRemainingTime % 60 << std::endl;
    }

    clear2DArray(tasks, tasksCount);
    delete[] pointsPerMinute;
    delete[] minutesPerDay;
    delete[] indexesOfTasks;

    return 0;
}

int readIntBiggerThan0()
{
    int result;
    bool validInput = true;
    do
    {
        if (!validInput)
        {
            std::cout << "Please enter a number bigger than 0: ";
        }
        validInput = true;
        std::cin >> result;
        while (!std::cin) // check if the input is a string
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number: ";
            std::cin >> result;
        }
        if (result < 1)
        {
            validInput = false;
        }
    } while (!validInput);

    return result;
}

void readNewRow(int ** array, int index)
{
    bool validInput = true;
    const char* text;
    do
    {
        if (!validInput)
        {
            std::cout << "Invalid task! " << text << "Please enter a new one: ";
        }
        validInput = true;
        std::cin >> array[index][0] >> array[index][1] >> array[index][2];
        while (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter only numbers: ";
            std::cin >> array[index][0] >> array[index][1] >> array[index][2];
        }
        if (array[index][1] < 1)
        {
            validInput = false;
            text = "The minutes must be bigger than 0! ";
        }
        if (array[index][2] < 1)
        {
            validInput = false;
            text = "The points must be bigger than 0! ";
        }
        for (int i = 0; i < index; ++i)
        {
            if (array[index][0] == array[i][0])
            {
                validInput = false;
                text = "This index is already used! ";
                break;
            }
        }
    } while (!validInput);
}

int ** allocate2DArray(size_t rows, size_t columns)
{
    int ** array = new(std::nothrow) int*[rows];
    if (!array)
    {
        std::cout << "Memory problem!" << std::endl;
        return array;
    }

    for (size_t i = 0; i < rows; ++i)
    {
        array[i] = new(std::nothrow) int[columns];
        if(!array[i])
        {
            std::cout << "Memory problem!" << std::endl;
            clear2DArray(array, rows);
            return nullptr;
        }
    }

    return array;
}

double* allocateDoubleArray(size_t size)
{
    double* array = new(std::nothrow) double[size];

    if(!array)
    {
        std::cout << "Memory problem!" << std::endl;
        return array;
    }

    return array;
}

int* allocateIntArray(size_t size)
{
    int* array = new(std::nothrow) int[size];

    if(!array)
    {
        std::cout << "Memory problem!" << std::endl;
        return array;
    }

    return array;
}

void clear2DArray(int ** array, size_t rows)
{
    for (size_t i = 0; i < rows; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
}

void swap(double* a, double* b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void swapRows(int** array, int row1, int row2)
{
    int* temp = array[row1];
    array[row1] = array[row2];
    array[row2] = temp;
}

int maxElement(double* array, size_t size)
{
    int max = 0;
    for (int i = 1; i < size; ++i)
    {
        if (array[i] > array[max])
        {
            max = i;
        }
    }

    return max;
}

void sortTasks(int** tasks, double* priority, size_t size) // descending selection sort
{
    for (int i = 0; i < size-1; ++i)
    {
        int minIndex = maxElement(priority+i, size-i) + i;
        swap(priority+i, priority+minIndex);
        swapRows(tasks, i, minIndex);
    }
}