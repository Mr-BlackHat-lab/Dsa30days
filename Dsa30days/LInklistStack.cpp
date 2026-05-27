#include <iostream>
#include "LinkedlistStack.h"

LinkedlistStack::LinkedlistStack(){
	head = nullptr;

}
LinkedlistStack::~LinkedlistStack() {
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
bool LinkedlistStack::isEmpty() const {
    return head == nullptr;	
}
void LinkedlistStack::push(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = head;

	head = newNode;

	std::cout << "value pushed succsefully\n";
	
}
int LinkedlistStack::pop() {
	if (isEmpty()) {
		std::cout << "Error Stack is Empty\n";
		return -1;
	}
	Node* temp = head;
	head = head->next;
	int val = temp->data;
	delete temp;
	return val;
}
int LinkedlistStack::peek() const {
	if (isEmpty()) {
		std::cout << "There is nothing to see stack is empty\n";
		return -1;
	}
	int val = head->data;
	return val;
}
void LinkedlistStack::traversal() const {
	if (isEmpty()) {
		std::cout << "There is nothing to see stack is empty\n";
		return;
	}
	Node* temp = head;
	while (temp != nullptr) {
		std::cout << temp->data << ".\n";
		temp = temp->next;
	}
}