// SelectionSort.cc

#include <climits>
#include "common.hh"
#include "SelectionSort.hh"

void selectionSort(int* arr, int n) {
    int minIdx = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

