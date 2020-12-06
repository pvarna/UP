#include <iostream>

int main()
{
    int h, m, t, startOfFlight, endOfFlight;

    std::cin >> h >> m >> t;

    startOfFlight = h * 60 + m;
    endOfFlight = startOfFlight + t;

    if (endOfFlight > 1440)
    {
        endOfFlight -= 1440;
    }

    std::cout << "The plane will arrive at " << endOfFlight / 60 << ":" << endOfFlight % 60 << std::endl;

    return 0;
}