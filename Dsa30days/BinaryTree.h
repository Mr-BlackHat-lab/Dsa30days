#pragma once

struct Node
{
	int data;
	Node* left;
	Node* right;
};
class BinaryTree {
private:
	int node_count;
	Node* root;

	//helper functions
	void destroy(Node* node);

	Node* insertHelper(Node* node, int value);

	int heightHelper(Node* node) const;

	void inOrderHelper(Node* node) const;
	void preOrderHelper(Node* node) const;
	void postOrderHelper(Node* node) const;

public:
	BinaryTree();
	~BinaryTree();

	bool isEmpty() const;

	void insert(int value);
	void remove(int value);
	bool search(int value) const;

	void peek_root() const;
	int treeHeight() const;

	void traverseInOrder() const;
	void traversePreOrder() const;
	void traversePostOrder() const;
};
