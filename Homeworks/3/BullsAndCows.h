#include <iostream>
//#include "BullsAndCows.cpp"
 
void play();

int s;
 
int* diff(int x, int y)
{
    int dx[4], dy[4];
    for(int i = 0; i < 4; i++)
    {
        dx[i] = x % 10;
        dy[i] = y % 10;
 
        x /= 10;
        y /= 10;
    }
 
    int *res = new int [2];
    res[0] = res[1] = 0;
    for(int i = 0; i < 4; i++)
    {
        if(dx[i] == dy[i])
            res[0]++;
        for(int j = 0; j < 4; j++)
        {
            if(dx[i] == dy[j])
                res[1]++;
        }
    }
 
    res[1] -= res[0];
    return res;
}
 
int times = 0;
const int* tryGuess(int x)
{
    times++;
 
    const int *res = diff(s, x);
    return res;
}
 
void load_test(int x)
{
    s = x;
    times = 0;
}
 
int main()
{
 
    int max_times = 0, avg_times = 0, plays = 0;
 
    for(int x = 1000; x <= 9999; x++)
    {
        int temp = x;
        int dig[10];
        for(int i = 0; i < 10; i++)
            dig[i] = 0;
 
        bool good = true;
        while(temp)
        {
            dig[temp % 10]++;
            if(dig[temp % 10] == 2)
                good = false;
            if(temp % 10 == 0)
                good = false;
            temp /= 10;
        }
 
        if(!good)
            continue;
 
        load_test(x);
        play();
 
        max_times = std::max(max_times, times);
        avg_times += times;
        plays++;
 
        std::cerr << x << " " << times << std::endl;
 
    }
 
    std::cout << max_times << " MAX" << std::endl;
    std::cout << (double)avg_times / plays << " AVG" << std::endl;
 
    return 0;
}