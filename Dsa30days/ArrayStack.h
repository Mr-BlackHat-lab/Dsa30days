#pragma once

class ArrayStack {
private:
	int* arr;
	int topIndex;
	int capacity;
public:
	ArrayStack(int size);
	~ArrayStack();
	void BubbleShort();
	void push(int value);
	void pop();
	int peek();
	void trav();
	bool isEmpty();
};