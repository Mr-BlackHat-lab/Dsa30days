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
    void MregesortRecursive(int left_index, int right_index); 
    void Merge(int left_index, int mid_index, int right_index);

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
    void CountingSort(int range_x, int range_y);
    
    // Public Quick Sort that automatically sorts the whole stack
    void Quicksort(); 
    void Mergesort();
};