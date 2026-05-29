#pragma once

struct Node
{
	Node* prev;
	int data;
	Node* next;
};


class LinkedListQueue {
private:
	Node* head;
	Node* last;
public:
	LinkedListQueue();
	~LinkedListQueue();
	bool isEmpty() const;
	int peek_first() const;
	int peek_last() const;
	void traversal() const;
	void enqueue(int value);
	int dequeue();
};
