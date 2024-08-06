// common.cc

#include "common.hh"

void swap(int* arr, int left, int right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

