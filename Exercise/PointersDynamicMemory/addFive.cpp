#include <iostream>

void addFive (int* number);

int main ()
{
    int myNumber = 3;

    std::cout << "My number is: " << myNumber << std::endl; 
    addFive(&myNumber);
    std::cout << "My number is: " << myNumber << std::endl; 

    return 0;
}

void addFive (int* number)
{
    *number = *number + 5;
}
