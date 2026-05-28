#include <iostream>
#include "ArrayQueue.h"

ArrayQueue::ArrayQueue(int size) {
	capacity = size;
	arr = new int[capacity];
	lastindex = -1;
}
ArrayQueue::~ArrayQueue() {
	delete[] arr;
}
bool ArrayQueue::isEmpty() const {
	return lastindex == -1;
}
int ArrayQueue::peek_first() const {
	if (isEmpty()) {
		std::cout << "Error Queue is empty\n";
		return -1;
	}
	return arr[0];
}
int ArrayQueue::peek_last() const {
	if (isEmpty()) {
		std::cout << "Error Queue is empty\n";
		return -1;
	}
	return arr[lastindex];
}

void ArrayQueue::push(int data) {
	if (lastindex == capacity-1) {
		std::cout << "Error queue overflow! queue is full\n";
		return;
	}
	lastindex++;
	arr[lastindex] = data;
	std::cout << data << " is succsefully pushed \n";
}
int ArrayQueue::pop() {
	if (isEmpty()) {
		std::cout << "Error! Queue is empty";
		return -1;
	}
	int temp = arr[0];
	for (int i = 0; i < lastindex;i++) {
		arr[i] = arr[i + 1];
	}
	lastindex--;
	return temp;
}
void ArrayQueue::traversal() const {
	if (isEmpty()) {
		std::cout << "Error! Queue is empty";
		return;
	}
	std::cout << "Traversing the queue\n";
	for (int i = 0; i <= lastindex;i++) {
		std::cout << arr[i] << "\n";
	}

}
