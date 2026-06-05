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
	if (topIndex == -1) {
		return true;
	}
	return false;
}
void ArrayStack::push(int value) {
	if (topIndex == capacity - 1) {
		std::cout << "Error stack overflow ! cannot push value " << value << ".\n";
		return;
	}
	topIndex++;
	arr[topIndex] = value;
	std::cout << "pushed the " << value << " in stack.\n";
}
void ArrayStack::pop() {
	if (isEmpty()) {
		std::cout << "Error stack is underflow ! cannot pop stack is already empty\n";
		return;
	}
	std::cout << "poped the value " << arr[topIndex] << ".\n";
	topIndex--;
}
int ArrayStack::peek() {
	if (isEmpty()) {
		std::cout << "Error stack is empty\n";
		return -1;
	}
	return arr[topIndex];
}
void ArrayStack::trav() {
	if (isEmpty()) {
		std::cout << "Error stack is empty\n";
		return;
	}
	std::cout << "listing the value in stack form top to bottom\n";
	for (int i = topIndex; i >= 0; i--) {
		std::cout << arr[i] << "\n";
	}
}
void ArrayStack::BubbleSort() {
	if (isEmpty()) {
		std::cout << "Error stack is empty\n";
		return;
	}
	std::cout << "Sorting the array in bubble short: \n";
	for (int i = topIndex;i >=0;i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void ArrayStack::SelectionSort() {
	if (isEmpty()) {
		std::cout << "Error stack is empty\n";
		return;
	}
	for (int i = 0; i < topIndex; i++) {
		int minIndex = i;
		for (int j = i; j < topIndex; j++) {

			if (arr[minIndex] > arr[j + 1]) {
				minIndex = j + 1;
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
	if (isEmpty()) {
		std::cout << "Error stack is empty\n";
		return;
	}
	for (int i = 1;i <= topIndex;i++) {
		int count = i;
		
		for (int j = 1;count > 0 && arr[count] < arr[count-1];j++) { // swap value till its smaller than its before value
			int temp = arr[count - 1];
			arr[count - 1] = arr[count];
			arr[count] = temp;
			count--;
		}
	}
}
