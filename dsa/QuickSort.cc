// QuickSort.cc

#include "QuickSort.hh"
#include "common.hh"

int partition(int* arr, int low, int high) {
    int pivot = (low + high) / 2;
    pprint("[debug]: pivot = " + std::to_string(pivot));
    pprint("[debug]: arr[pivot] = " + std::to_string(arr[pivot]));
    int left = low, right = high;
    while (left <= right) {
        while (arr[low] < arr[pivot]) {
            low++;
        }
        while (arr[high] >= arr[pivot]) {
            high--;
        }
        if (left < right) {
            swap(arr, left, right);
            low++;
            high--;
        }
    }
    return pivot;
}

void quickSort(int* arr, int low, int high) {
    int partitionIdx = partition(arr, low, high);
    quickSort(arr, partitionIdx + 1, high);
    quickSort(arr, low, partitionIdx - 1);
}

