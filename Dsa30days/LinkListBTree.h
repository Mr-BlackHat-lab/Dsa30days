#pragma once

struct Node {
	Node* prev;
	Node* left;
	Node* right;
	int data;
};
class LinkListBTree {
private:
	Node* head;
	int nodes = 0;
	void inorder(Node* node) const;
	void destroy(Node* node);
	int height(Node* node) const;
public:
	LinkListBTree();
	~LinkListBTree();
	bool isEmpty();
	void push(int value);
	void traversal() const;
	int peek_head() const;
	int tree_nodes() const;
	int tree_height() const;
};
