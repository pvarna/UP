#include <iostream>
#include <limits>

// reads an int and validates if the input is a number and if it is bigger than 0
int readIntBiggerThan0(const char* what);

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

// recursive function
// brute-force search
// checks all possibilities to collect as many points as possible
void findBestOption(int** tasks, int tasksCount, int availableTime, int& index, int& timeSoFar,
                    int& pointsSoFar, int* tasksTaken, int& countTaken, int* tasksResult, int& maxPoints, int& countResult);

int main ()
{
    int tasksCount, remainingDays, availableTime = 0;

    tasksCount = readIntBiggerThan0("tasksCount");

    // allocating memory for the arrays
    int** tasks = allocate2DArray(tasksCount, 3);
    double* pointsPerMinute = allocateDoubleArray(tasksCount);

    for (int i = 0; i < tasksCount; ++i)
    {
        readNewRow(tasks, i);
        pointsPerMinute[i] = (double)tasks[i][2] / (double)tasks[i][1]; // calculating points per minute for each task
    }

    remainingDays = readIntBiggerThan0("remainingDays");

    int * minutesPerDay = allocateIntArray(remainingDays);

    for (int i = 0; i < remainingDays; ++i)
    {
        minutesPerDay[i] = readIntBiggerThan0("minutes");
        availableTime += minutesPerDay[i];
    }

    sortTasks(tasks, pointsPerMinute, tasksCount);

    int* tasksTaken = allocateIntArray(tasksCount);
    int* tasksResult = allocateIntArray(tasksCount);
    int index = 0, timeSoFar = 0, pointsSoFar = 0, countResult = 0, countTaken = 0, maxPoints = 0;
    
    findBestOption(tasks, tasksCount, availableTime, index, timeSoFar, pointsSoFar, tasksTaken, countTaken, tasksResult, maxPoints, countResult);

    if (countResult == 0)
    {
        std::cout << "There is no time for any tasks" << std::endl;
    }
    else
    {
        std::cout << "Tasks: " << tasks[tasksResult[0]][0];
        availableTime -= tasks[tasksResult[0]][1];

        for (int i = 1; i < countResult; ++i)
        {
            std::cout << ", " << tasks[tasksResult[i]][0];
            availableTime -= tasks[tasksResult[i]][1];
        }
        std::cout << std::endl;

        const char* leadingZero = "";
        if (availableTime % 60 < 10)
        {
            leadingZero = "0";
        } 
        std::cout << "Time remaining: " << availableTime / 60 << ":" << leadingZero << availableTime % 60 << std::endl;
    }

    clear2DArray(tasks, tasksCount);

    delete[] pointsPerMinute;
    delete[] minutesPerDay;
    delete[] tasksTaken;
    delete[] tasksResult;

    return 0;
}

int readIntBiggerThan0(const char* what)
{
    int result;
    bool validInput = true;
    const char* text;

    do
    {
        if (!validInput)
        {
            std::cout << text;
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
            text = "Please enter a number bigger than 0: ";
        }

        if (what == "minutes" && result > 24*60)
        {
            validInput = false;
            text = "There are not that many minutes in one day! Please enter a new number: ";
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

        if (array[index][2] < 0)
        {
            validInput = false;
            text = "The points must be 0 or а positive number! ";
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

void findBestOption(int** tasks, int tasksCount, int availableTime, int& index, int& timeSoFar, int& pointsSoFar, 
                    int* tasksTaken, int& countTaken, int* tasksResult, int& maxPoints, int& countResult)
{
    if (index == tasksCount) // if we have reached the end
    {
        if (pointsSoFar > maxPoints) // check if this sequence of tasks is better
        {
            maxPoints = pointsSoFar;
            for (int i = 0; i < countTaken; ++i)
            {
                tasksResult[i] = tasksTaken[i];
            }
            countResult = countTaken;
        }
        return;
    }

    // We have two options
    // 1. We take the task because we have that much time available
    if (timeSoFar + tasks[index][1] <= availableTime)
    {
        tasksTaken[countTaken] = index;
        timeSoFar += tasks[index][1];
        pointsSoFar += tasks[index][2];
        ++index;
        ++countTaken;

        findBestOption(tasks, tasksCount, availableTime, index, timeSoFar, pointsSoFar, tasksTaken, countTaken, tasksResult, maxPoints, countResult);
        
        --countTaken;
        --index;
        pointsSoFar -= tasks[index][2];
        timeSoFar -= tasks[index][1];
    }

    // or
    // 2. We do not take the task because we do not have that much time available

    ++index;

    findBestOption(tasks, tasksCount, availableTime, index, timeSoFar, pointsSoFar, tasksTaken, countTaken, tasksResult, maxPoints, countResult);
    
    --index;
}