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