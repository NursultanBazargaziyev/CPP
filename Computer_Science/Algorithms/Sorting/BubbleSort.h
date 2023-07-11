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


template<typename T>
void bubbleSort(std::vector<T> &arr){

    for (int i = arr.size() - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if(arr[j] > arr[j+1])
                std::swap(arr[j], arr[j+1]);
        }
    }
}