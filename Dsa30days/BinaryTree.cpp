#include <iostream>
#include "BinaryTree.h"

BinaryTree::BinaryTree() {
	node_count = 0;
	root = nullptr;
}
BinaryTree::~BinaryTree() {
	destroy(root);
}
void BinaryTree::destroy(Node* node) {
	if (!node) return;
	destroy(node->left);
	destroy(node->right);
	delete node;
}
bool BinaryTree::isEmpty() const {
	return root == nullptr;
}
bool BinaryTree::search(int value) const {
	if (isEmpty()) return false;
	Node* temp = root;
	while (temp != nullptr) {
		if (temp->data == value) return true;
		if (temp->data < value) {
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	return false;
}
Node* BinaryTree::insertHelper(Node* node, int value) {
	if(node==nullptr){
		Node* newNode = new Node;
		newNode->data = value;
		newNode->left = newNode->right = nullptr;
		return newNode;
	}
	if (node->data < value) {
		node->right = insertHelper(node->right, value);
	}
	else
	{
		node->left = insertHelper(node->left, value);
	}
	return node;
}
void BinaryTree::insert(int value) {
	if (search(value)) {
		std::cout << "Value:"<<value<<" already exits in tree";
		return;
	}
	root = insertHelper(root, value);
	std::cout << "value:" << value << " is sucssefully pushed";
	node_count++;
}