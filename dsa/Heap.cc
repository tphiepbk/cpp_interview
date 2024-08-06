// Heap.cc

#include "Heap.hh"
#include "common.hh"
#include <string>

// Knowledge
// When we represent a heap as an array of N elements
// - Last internal (non-leaf) node: (N / 2) - 1
// - For a element at index i < N:
//      - Left child: 2 * i + 1
//      - Right child: 2 * i + 2
//      - Parent: (i - 1) / 2

void heapify(int* arr, int i, int N, bool isMaxHeap) {
    int leftChildIndex = 2 * i + 1;
    int rightChildIndex = 2 * i + 2;
    int chosenIndex = 0;
    if (leftChildIndex < N && rightChildIndex < N) {
        if (isMaxHeap) {
            if (arr[leftChildIndex] >= arr[rightChildIndex]) {
                chosenIndex = leftChildIndex;
            } else {
                chosenIndex = rightChildIndex;
            }
        } else {
            if (arr[leftChildIndex] < arr[rightChildIndex]) {
                chosenIndex = leftChildIndex;
            } else {
                chosenIndex = rightChildIndex;
            }
        }
    } else if (leftChildIndex < N) {
        chosenIndex = leftChildIndex;
    } else if (rightChildIndex < N){
        chosenIndex = rightChildIndex;
    } else {
        return;
    }
    if (isMaxHeap) {
        if (arr[i] < arr[chosenIndex]) {
            swap(arr, i, chosenIndex);
            heapify(arr, chosenIndex, N, isMaxHeap);
        }
    } else {
        if (arr[i] >= arr[chosenIndex]) {
            swap(arr, i, chosenIndex);
            heapify(arr, chosenIndex, N, isMaxHeap);
        }
    }
}

void buildMaxHeap(int* arr, int N) {
    int lastNonLeafIndex = (N / 2) - 1;
    for (int i = lastNonLeafIndex; i >= 0; i--) {
        heapify(arr, i, N, true);
    }
}

void buildMinHeap(int* arr, int N) {
    int lastNonLeafIndex = (N / 2) - 1;
    for (int i = lastNonLeafIndex; i >= 0; i--) {
        heapify(arr, i, N, false);
    }
}
