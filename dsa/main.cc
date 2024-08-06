// main.cc

#include "BubbleSort.hh"
#include "QuickSort.hh"
#include "SelectionSort.hh"
#include "Heap.hh"
#include "common.hh"

void printArr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    // int n = 4, ub = 20, lb = 1;
    // int* arr = new int[n];
    // for (int i = 0; i < n; i++) {
    //     arr[i] = rand() % (ub - lb + 1);
    // }

    int arr[8] = {5, 12, 64, 1, 37, 90, 91, 97};
    int n = 8;

    section("Original array");
    printArr(arr, n);

    // section("Quick sort");
    // quickSort(arr, 0, n-1);
    // printArr(arr, n);

    section("Bubble sort");
    bubbleSort(arr, n);
    printArr(arr, n);

    section("Selection sort");
    selectionSort(arr, n);
    printArr(arr, n);

    section("Max heap");
    buildMaxHeap(arr, n);
    printArr(arr, n);

    section("Min heap");
    buildMinHeap(arr, n);
    printArr(arr, n);

    // delete[] arr;
    // arr = nullptr;
}
