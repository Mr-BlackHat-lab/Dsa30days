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