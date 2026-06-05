#pragma once

class ArrayStack {
private:
	int* arr;
	int topIndex;
	int capacity;
public:
	ArrayStack(int size);
	~ArrayStack();
	void BubbleSort();
	void SelectionSort();
	void InsertionSort();
	void push(int value);
	void pop();
	int peek();
	void trav();
	bool isEmpty();
};