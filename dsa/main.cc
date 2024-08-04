// main.cc

#include "Sorting.hh"
#include "define.hh"

void printArr(uint* arr, uint n) {
    for (uint i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    uint n = 6, ub = 20, lb = 1;
    uint* arr = new uint[n];
    for (uint i = 0; i < n; i++) {
        arr[i] = rand() % (ub - lb + 1);
    }
    printArr(arr, n);

    // bubbleSort
    bubbleSort(arr, n);
    printArr(arr, n);

    delete[] arr;
    arr = nullptr;
}
