#include <iostream>
#include "ArrayStack.h"

ArrayStack::ArrayStack(int size) {
    capacity = size;
    arr = new int[capacity];
    topIndex = -1;
}

ArrayStack::~ArrayStack() {
    delete[] arr;
}

bool ArrayStack::isEmpty() {
    return topIndex == -1;
}

void ArrayStack::push(int value) {
    if (topIndex == capacity - 1) {
        std::cout << "Error: Stack overflow! Cannot push value " << value << ".\n";
        return;
    }
    topIndex++;
    arr[topIndex] = value;
    std::cout << "Pushed " << value << " into the stack.\n";
}

void ArrayStack::pop() {
    if (isEmpty()) {
        std::cout << "Error: Stack underflow! Cannot pop, stack is empty.\n";
        return;
    }
    std::cout << "Popped the value " << arr[topIndex] << ".\n";
    topIndex--;
}

int ArrayStack::peek() {
    if (isEmpty()) {
        std::cout << "Error: Stack is empty.\n";
        return -1;
    }
    return arr[topIndex];
}

void ArrayStack::trav() {
    if (isEmpty()) {
        std::cout << "Error: Stack is empty.\n";
        return;
    }
    std::cout << "Listing values in stack from top to bottom:\n";
    for (int i = topIndex; i >= 0; i--) {
        std::cout << arr[i] << "\n";
    }
}

void ArrayStack::BubbleSort() {
    if (isEmpty()) return;
    std::cout << "Sorting the array with Bubble Sort...\n";
    for (int i = topIndex; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void ArrayStack::SelectionSort() {
    if (isEmpty()) return;
    std::cout << "Sorting the array with Selection Sort...\n";
    for (int i = 0; i < topIndex; i++) {
        int minIndex = i;
        for (int j = i + 1; j <= topIndex; j++) { // Fixed boundary condition
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void ArrayStack::InsertionSort() {
    if (isEmpty()) return;
    std::cout << "Sorting the array with Insertion Sort...\n";
    for (int i = 1; i <= topIndex; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort Implementations
int ArrayStack::partition(int low, int high) {
    int pivot = arr[low];
    int p = low + 1;
    int q = high;

    while (true) {
        while (p <= high && arr[p] <= pivot) {
            p += 1;
        }
        while (q >= low && arr[q] > pivot) {
            q -= 1; 
        }
        
        if (p < q) { 
            int temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
        } else {
            break;
        }
    }
    int temp = arr[low];
    arr[low] = arr[q];
    arr[q] = temp;
    return q;
}

void ArrayStack::QuicksortRecursive(int low, int high) {
    if (low < high) {
        int pivot_index = partition(low, high);
        QuicksortRecursive(low, pivot_index - 1);
        QuicksortRecursive(pivot_index + 1, high);
    }
}

// Public wrapper so you don't have to pass array indexes in main()
void ArrayStack::Quicksort() {
    if (isEmpty()) return;
    std::cout << "Sorting the array with Quick Sort...\n";
    QuicksortRecursive(0, topIndex);
}