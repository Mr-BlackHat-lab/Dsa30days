#pragma once

class ArrayQueue {
private:
	int capacity;
	int* arr;
	int lastindex;
public:
	ArrayQueue(int size);
	~ArrayQueue();
	int peek_first() const;
	int peek_last() const;
	bool isEmpty() const;
	void traversal() const;
	int pop();
	void push(int data);
};
