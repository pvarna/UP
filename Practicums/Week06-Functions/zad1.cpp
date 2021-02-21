#include <iostream>

int main ()
{
    int n, number, maxNegativeNumber = 0;
    //bool areThereNegativeNumbers = false;

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> number;

        if (number < 0 && (number > maxNegativeNumber || maxNegativeNumber == 0))
        {
            maxNegativeNumber = number;
            //areThereNegativeNumbers = true;
        }
        //std::cout << minNegativeNumber << std::endl;
    }

    std::cout << maxNegativeNumber << std::endl;

    /*if (areThereNegativeNumbers)
    {
        std::cout << maxNegativeNumber << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }*/
    

    return 0;
}