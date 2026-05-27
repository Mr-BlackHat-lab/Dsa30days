#pragma once

struct Node {
	int data;
	Node* next;
};
class LinkedlistStack {
private:
	Node* head;
public:
	LinkedlistStack();
	~LinkedlistStack();
	void push(int data);
	int pop();
	int peek() const;
	void traversal() const;
	bool isEmpty() const;
};
