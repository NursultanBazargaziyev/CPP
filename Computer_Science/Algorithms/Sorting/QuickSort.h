// Bazargaziyev Nursultan
// 29-06-2023

// Implementation of QuickSort;
// Worst case: O(n^2);
// Average/best case O(nlogn)

#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

template<typename T>
int partition(std::vector<T>&, int, int);


template<typename T>
void printArray(const std::vector<T>& arr){
    std::copy(arr.begin(),arr.end(), std::ostream_iterator<T>(std::cout, ", "));
}

template<typename T>
void quickSort(std::vector<T>& arr, int l, int r){
    if (l < r) {
		int pi = partition(arr, l, r);
		quickSort(arr, l, pi - 1);
		quickSort(arr, pi + 1, r);
	}
}

template<typename T>
int partition(std::vector<T>& arr, int l, int r){
    T pivot = arr[r];
	int i = l, j = l - 1;
	while (i < r) {
		if (arr[i] < pivot) {
			j++;
			std::swap(arr[i], arr[j]);
		}
		i++;
	}
	std::swap(arr[j + 1], arr[r]);
	return ++j;
}