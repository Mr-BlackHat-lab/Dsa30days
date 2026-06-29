#pragma once

struct Node
{
	int data;
	Node* parent;
	Node* left;
	Node* right;
};
class BasicTree {
private:
	Node* root;
	int node_count;
public:
	
	BasicTree();
	~BasicTree();

	bool isEmpty() const;

	//core operation
    void insert(int value);
    void remove(int value);
    bool search(int value) const;

    // Utilities
    void peek_root() const;
    int treeHeight() const;

    // Trees have 3 distinct ways to traverse!
    void traverseInOrder() const;
    void traversePreOrder() const;
    void traversePostOrder() const;
};