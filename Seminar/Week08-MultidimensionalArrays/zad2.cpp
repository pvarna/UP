#include <iostream>

const int MAX_ARRAY_SIZE = 100;

size_t readSize ();

void readArray (int arr[], size_t size);

int countOfFirstArrayInTheSecond (int arr1[], int arr2[], size_t size1, size_t size2);

void printArray (int arr[], size_t size);

int main ()
{
    size_t size1, size2;
    int numbers1[MAX_ARRAY_SIZE], numbers2[MAX_ARRAY_SIZE];

    size1 = readSize ();
    readArray (numbers1, size1);
    size2 = readSize ();
    readArray (numbers2, size2);

    /*std::cout << std::endl;
    printArray (numbers1, size1);
    printArray (numbers2, size2);*/

    if (size2 >= size1)
    {
        std::cout << countOfFirstArrayInTheSecond(numbers1, numbers2, size1, size2);
    }
    else
    {
        std::cout << "The first row of elements is longer that the second" << std::endl;
    }
    

    return 0;
}

size_t readSize ()
{
    size_t n;
    do
    {
        std::cout << "N = ";
        std::cin >> n;
    } 
    while (n == 0 || n > MAX_ARRAY_SIZE);

    return n;    
}

void readArray (int arr[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
}

int countOfFirstArrayInTheSecond (int arr1[], int arr2[], size_t size1, size_t size2)
{
    int counter = 0;
    for (int i = 0; i < size2-size1+1; ++i)
    {
        if (arr2[i] == arr1[0])
        {
            bool flag = true;
            for (int j = 1; j < size1; ++j)
            {
                if (arr2[i+j] != arr1[j])
                {
                    //std::cout << arr2[i+j] << " " << arr1[j] << " " << i << " " << j << std::endl;
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ++counter;
            }
        }
    }
    return counter;
}

void printArray (int arr[], size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}