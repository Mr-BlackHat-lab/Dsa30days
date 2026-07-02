#pragma once

struct Node
{
	int data;
	int height;
	Node* left;
	Node* right;
};

class AvlTree
{
private:
	Node* root;
	int node_count;

	int getHeight(Node* node);
	int getBalanceFactor(Node* node);

	Node* rightRotate(Node* y);
	Node* leftRotate(Node* x);

	//helpers
	void destroy(Node* node);

	Node* insertHelper(Node* node, int value);
	Node* removeHelper(Node* node, int value);

	int treeheightHelper(Node* node) const;
	void preorderHelper(Node* node) const;
	void postorderHelper(Node* node) const;
	void inorderHelper(Node* node) const;

public:
	AvlTree();
	~AvlTree();

	bool isEmpty() const;

	bool search(int value) const;
	void insert(int value);
	void remove(int value);

	void peek_root() const;
	void tree_height() const;

	void pre_orderTraversal() const;
	void post_orderTraversal() const;
	void in_orderTraversal() const;

};
