#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

const int MAX_BAR_SIZE = 500;

void updateProgressBar(char bar[], double currentProgress, char openSymbol, char closeSymbol, bool showPercentages, char fillSymbol, char emptySymbol, int numberOfDivisions);

void printArray(char array[], size_t size);

// input + vaidation
int inputSeconds();

// rounds a double type to 2 digits after the decimal point
double round(double number);

int main ()
{
    // parameters of the function
    char bar[MAX_BAR_SIZE] = {};
    double currentProgress = 0;
    char openSymbol = '[';
    char closeSymbol = ']';
    char fillSymbol = '-';
    char emptySymbol = ' ';
    bool showPercenteges = true;
    int numberOfDivisions = 100;

    size_t size = numberOfDivisions + 2; // + open and close symbols

    // fixing double precision problem
    currentProgress = round(currentProgress);
    int startingPercentage = (int)(ceil(currentProgress*100)); // calculating the starting percentage of the progress bar

    int seconds = inputSeconds(); // input

    int millisecondsPerPercentage = seconds*1000/(100-startingPercentage); // calculatting how many milliseconds per percentage are needed

    for (int i = startingPercentage; i <= 100; ++i)
    {
        updateProgressBar(bar, (double(i)/100.0), openSymbol, closeSymbol, showPercenteges, fillSymbol, emptySymbol, numberOfDivisions);
        printArray(bar, size);
        std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsPerPercentage));
        
        if (i != 100)
        {
            system("cls");
        }
    }

    return 0;
}

void printArray(char array[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << array[i];
    }
    std::cout << std::endl;
}

double round(double number)
{
    // 0.9499999999999999556 * 100 = 94.999999999999999556 
    // 94.999999999999999556 + 0.5 = 95.499999999999999556    for rounding off value 
    // then type cast to int so value is 95 
    // then divided by 100 so the value converted into 0.95 
    double value = (int)(number * 100 + 0.5); 
    return (double)value / 100; 
}

int inputSeconds()
{
    int seconds, counter = 0;
    do
    {
        if (counter > 0)
        {
            std::cout << "Please enter valid seconds (number bigger than 0)!" << std::endl;
        }
        std::cin >> seconds;
        ++counter;

    } while (seconds < 1);

    return seconds;
}

void updateProgressBar(char bar[], double currentProgress, char openSymbol, char closeSymbol, bool showPercentages, char fillSymbol, char emptySymbol, int numberOfDivisions)
{
    // again fixing double precision problem
    currentProgress = round(currentProgress);
    int currentPercentage = (int)(ceil(currentProgress*100)); // calculating the current percentage of the progress bar
    int numberOfFillSymbols = currentPercentage*numberOfDivisions/100; // calculating the number of fill symbols
    
    size_t size = numberOfDivisions+2; // + open and close symbols

    bar[0] = openSymbol;
    if (showPercentages) // add percentages in the middle of the bar if they have to be displayed
    {
        if (currentPercentage < 10)
        {
            bar[size/2-1] = '0' + currentPercentage;
            bar[size/2] = '%';  
        }
        else if (currentPercentage != 100)
        {
            bar[size/2-1] = '0' + (currentPercentage/10);
            bar[size/2] = '0' + (currentPercentage%10);
            bar[size/2+1] = '%';
        }
        else
        {
            bar[size/2-2] = '1';
            bar[size/2-1] = '0';
            bar[size/2] = '0';
            bar[size/2+1] = '%';
        }
    }

    // fill the bar with fill and empty symbols
    for (int i = 1; i <= numberOfDivisions; ++i)
    {
        if ((bar[i] < '0' || bar[i] > '9') && bar[i] != '%') // don't put anything if there is a percantage on that position
        {
            if (i <= numberOfFillSymbols)
            {
                bar[i] = fillSymbol;
            }
            else
            {
                bar[i] = emptySymbol;
            }
        }
    }
    
    bar[size-1] = closeSymbol;   
}