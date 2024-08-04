// Sorting.cc

#include "Sorting.hh"
#include "define.hh"

void bubbleSort(uint* arr, uint n) {
    pprint("bubbleSort: is called");
    for (uint i = 0; i < n-1; i++) {
        for (uint j = 0; j < n-i-1; j++) {
            if (arr[j] >= arr[j+1]) {
                uint temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
