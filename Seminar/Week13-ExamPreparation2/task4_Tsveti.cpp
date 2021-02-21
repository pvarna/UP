#include <iostream>

int* getLongestSubArray(int* arr, size_t size, int& maxLen);

int main ()
{
    size_t size;
    int* arr = new(std::nothrow) int[size];
    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    int maxLen;

    int* result = getLongestSubArray(arr, size, maxLen);
    for (int i = 0; i < maxLen; ++i)
    {
        std::cout << result[i] << " ";
    }

    delete[] arr;
    delete[] result;

    return 0;
}

void longestSubArrayHelper(int* arr, size_t size, int& maxStart, int& maxLen, int count, bool isSubArray, int start, int len)
{
    if (count == size)
    {
        if (isSubArray && len > maxLen)
        {
            maxLen = len;
            maxStart = start;
        }
        return;
    }
    if (arr[count] == arr[count-1])
    {
        if (!isSubArray)
        {
            isSubArray = true;
            start = count-1;
            ++len;
        }
        ++len;
    }
    else
    {
        if (isSubArray)
        {
            if (len > maxLen)
            {
                maxLen = len;
                maxStart = start;
                start = 0;
                len = 0;
            }
            isSubArray = false;
        }
    }
    longestSubArrayHelper(arr, size, maxStart, maxLen, ++count, isSubArray, start, len);
}

int* getLongestSubArray(int* arr, size_t size, int& maxLen)
{
    int maxStart = 0;
    maxLen = 0;

    longestSubArrayHelper(arr, size, maxStart, maxLen, 1, false, 0, 0);

    int* longestSubArray = new(std::nothrow) int[maxLen];
    int j = 0;
    for (int i = maxStart; i < size - maxLen + maxStart; ++i)
    {
        longestSubArray[j] = arr[i];
        ++j;
    }

    return longestSubArray;
}