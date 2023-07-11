// Bazargaziyev Nursultan

// 11-07-2023

// Implementation of Selection Sort;
// Worst case: O(n^2);
// Average/best case O(n^2)

#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

template <typename T>
void printArray(const std::vector<T> &arr)
{
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<T>(std::cout, ", "));
}

template <typename T>
void selectionSort(std::vector<T> &arr)
{
    if (arr.empty())
        return;

    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = i; j < arr.size(); ++j)
        {
            if (arr[i] > arr[j])
                std::swap(arr[j], arr[i]);
        }
    }
}