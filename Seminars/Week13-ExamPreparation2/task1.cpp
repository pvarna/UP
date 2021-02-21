#include <iostream>

bool checkForPermutation(int* arr1, int* arr2, size_t size1, size_t size2);

int main ()
{
    size_t size1, size2;
    int* arr1 = new(std::nothrow) int[size1];
    int* arr2 = new(std::nothrow) int[size2];

    std::cin >> size1;
    for (int i = 0; i < size1; ++i)
    {
        std::cin >> arr1[i];
    }

    std::cin >> size2;
    for (int i = 0; i < size2; ++i)
    {
        std::cin >> arr2[i];
    }

    std::cout << std::boolalpha << checkForPermutation(arr1, arr2, size1, size2) << std::endl;

    delete[] arr1;
    delete[] arr2;

    return 0;
}

bool checkForPermutation(int* arr1, int* arr2, size_t size1, size_t size2)
{
    if (size1 != size2)
    {
        return false;
    }

    bool* visit = new(std::nothrow) bool[size2]{};
    
    for (int i = 0; i < size1; ++i)
    {
        bool match = false;
        for (int j = 0; j < size2; ++j)
        {
            if (!visit[j] && arr1[i] == arr2[j])
            {
                visit[j] = true;
                match = true;
                break;
            }
        }
        if (!match)
        {
            return false;
        }
    }
    return true;

    delete[] visit;
}