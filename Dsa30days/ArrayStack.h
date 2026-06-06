#pragma once

class ArrayStack {
private:
    int* arr;
    int topIndex;
    int capacity;
    
    // Helper function for Quick Sort
    int partition(int low, int high); 
    // Internal recursive function
    void QuicksortRecursive(int low, int high); 

public:
    ArrayStack(int size);
    ~ArrayStack();
    
    // Stack Operations
    void push(int value);
    void pop();
    int peek();
    void trav();
    bool isEmpty();

    // Sorting Algorithms
    void BubbleSort();
    void SelectionSort();
    void InsertionSort();
    
    // Public Quick Sort that automatically sorts the whole stack
    void Quicksort(); 
};