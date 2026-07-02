#include <iostream>
#include "AvlTree.h"

AvlTree::AvlTree() {
	root = nullptr;
	node_count = 0;
}
AvlTree::~AvlTree() {
	destroy(root);
}
void AvlTree::destroy(Node* node) {
	if (!node) return;
	destroy(node->left);
	destroy(node->right);
	delete node;
}
int AvlTree::getHeight(Node* node) {
	if (!node) return 0;
	return node->height;
}
int AvlTree::getBalanceFactor(Node* node) {
	if (!node) return 0;
	return (getHeight(node->left) - getHeight(node->right));
}