#include "MaxHeap.h"
#include <vector>
#include <iostream>

MaxHeap::MaxHeap() {}
MaxHeap::~MaxHeap() {
	heap.clear();
}

bool MaxHeap::isEmpty() const {
	if (heap.empty()) return true;
	return false;
}

int MaxHeap::getSize() const {
	int size = heap.size();
	return size;
}

void MaxHeap::insert(int value) {
	heap.push_back(value);
	int index = getSize() - 1;
	heapifyUp(index);
}
int MaxHeap::extractMax() {
	if (isEmpty()) throw std::runtime_error("Heap is empty");
	int top = heap.at(0);
	heap[0] = heap.back();
	heap.pop_back();
	heapifyDown(0);
	return top;
}

int MaxHeap::peekMax() const {
	return heap.at(0);
}

void MaxHeap::printHeap() const {
	int i = 0;
	while (i < getSize()) {
		std::cout << heap.at(i) << " \n";
		i++;
	}
}

int MaxHeap::parent(int index) const {
	int parentIndex = (index - 1) / 2;
	return parentIndex;
}
int MaxHeap::leftChild(int index) const {
	int leftChildIndex = (index * 2) + 1;
	return leftChildIndex;
}
int MaxHeap::rightChild(int index) const {
	int rightChildIndex = (index * 2) + 2;
	return rightChildIndex;
}

void MaxHeap::heapifyUp(int index) {
	while (index > 0) {
		int pIndex = parent(index); 
		if (heap.at(index) > heap.at(pIndex)) {			
			std::swap(heap[index], heap[pIndex]);
			index = pIndex; 
		}
		else {			
			break;
		}
	}
}

void MaxHeap::heapifyDown(int index) {
	while (leftChild(index) < heap.size()) {
		int leftChildIndex = leftChild(index);
		int largerChildIndex;
		if (rightChild(index) < heap.size()&&heap.at(leftChildIndex) < heap.at(rightChild(index))) {
			largerChildIndex = rightChild(index);
		}
		else {
			largerChildIndex = leftChildIndex;
		}
		if (heap.at(index) < heap.at(largerChildIndex)) {
			std::swap(heap[index], heap[largerChildIndex]);
			index = largerChildIndex;
		}
		else {
			break;
		}
	}
}