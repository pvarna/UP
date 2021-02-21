#include <iostream>
#include <cmath>

struct Bench
{
    double x;
    double y;
};

struct Lamp
{
    double x;
    double y;
    double radius;
};

double myFabs(double x, double y);

double mySqrt(double x);

bool checkIfABenchIsIlluminatedByALamp(Bench bench, Lamp lamp);

bool checkIfAllBenchesAreIlluminated(Bench* benches, int countOfBenches, Lamp* lamps, int countOfLamps);

void findMinimumLamps(Bench* benches, int countOfBenches, Lamp* lamps, int countOfLamps, int currentLamp, int& minCountOfLamps, Lamp* minLamps, int currentCountOfLamps, Lamp* currentLamps);

int main ()
{
    int n, m;
    
    std::cin >> n;
    Bench* benches = new(std::nothrow) Bench[n];
    if (!benches)
    {
        std::cout << "Memory problem!" << std::endl;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> benches[i].x >> benches[i].y;
    }

    std::cin >> m;
    Lamp* lamps = new(std::nothrow) Lamp[n];
    if (!lamps)
    {
        std::cout << "Memory problem!" << std::endl;
        return 0;
    }

    for (int i = 0; i < m; ++i)
    {
        std::cin >> lamps[i].x >> lamps[i].y >> lamps[i].radius;
    }

    std::cout << std::boolalpha << checkIfAllBenchesAreIlluminated(benches, n, lamps, m) << std::endl;

    int minCountOfLamps = m;
    Lamp currentLamps[100], minLamps[100];

    findMinimumLamps(benches, n, lamps, m, 0, minCountOfLamps, minLamps, 0, currentLamps);

    std::cout << minCountOfLamps << std::endl;

    for (int i = 0; i < minCountOfLamps; ++i)
    {
        std::cout << minLamps[i].x << " " << minLamps[i].y << " " << minLamps[i].radius;
    }


    delete[] benches;
    delete[] lamps;

    return 0;
}

bool checkIfABenchIsIlluminatedByALamp(Bench bench, Lamp lamp)
{
    double differenceX = fabs(bench.x - lamp.x);
    double differenceY = fabs(bench.y - lamp.y);
    double difference = sqrt(differenceX*differenceX + differenceY*differenceY);

    return (lamp.radius >= difference) ? true : false;
}

bool checkIfAllBenchesAreIlluminated(Bench* benches, int countOfBenches, Lamp* lamps, int countOfLamps)
{
    for (int i = 0; i < countOfBenches; ++i)
    {
        bool benchIlluminated = false;
        for (int j = 0; j < countOfLamps; ++j)
        {
            if (checkIfABenchIsIlluminatedByALamp(benches[i], lamps[j]))
            {
                benchIlluminated = true;
                break;
            }
        }
        if (!benchIlluminated)
        {
            return false;
        }
    }
    return true;
}

void findMinimumLamps(Bench* benches, int countOfBenches, Lamp* lamps, int countOfLamps, int currentLamp, int& minCountOfLamps, Lamp* minLamps, int currentCountOfLamps, Lamp* currentLamps)
{
    if (currentLamp == countOfLamps)
    {
        return;
    }
    if (currentCountOfLamps >= minCountOfLamps)
    {
        return;
    }
    if (checkIfAllBenchesAreIlluminated(benches, countOfBenches, currentLamps, currentCountOfLamps))
    {
        if (currentCountOfLamps < minCountOfLamps)
        {
            minCountOfLamps = currentCountOfLamps;
            for (int i = 0; i < currentCountOfLamps; ++i)
            {
                minLamps[i] = currentLamps[i];
            }
        }
        return;
    }

    Lamp lampsTemp[100];
    for (int i = 0; i < currentCountOfLamps; ++i)
    {
        lampsTemp[i] = currentLamps[i];
    }
    ++currentLamp;
    findMinimumLamps(benches, countOfBenches, lamps, countOfLamps, currentLamp, minCountOfLamps, minLamps, currentCountOfLamps, lampsTemp);
    --currentLamp;

    lampsTemp[currentCountOfLamps] = lamps[currentLamp];
    ++currentCountOfLamps;
    ++currentLamp;
    findMinimumLamps(benches, countOfBenches, lamps, countOfLamps, currentLamp+1, minCountOfLamps, minLamps, currentCountOfLamps, lampsTemp);
    --currentLamp;
}