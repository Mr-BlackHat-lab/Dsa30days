#pragma once

#include <vector>

class MaxHeap
{
public:
	MaxHeap();
	~MaxHeap();

	bool isEmpty() const;
	int getSize() const;

	void insert(int value);
	int extractMax();//remove and get biggest value in max queue
	int peekMax() const;

	void printHeap() const;

private:
	std::vector<int> heap;

	int parent(int index) const;
	int leftChild(int index) const;
	int rightChild(int index) const;

	void heapifyUp(int index);
	void heapifyDown(int index);
};
