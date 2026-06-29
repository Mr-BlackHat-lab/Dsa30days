#include <iostream>
#include "BasicTree.h"

BasicTree::BasicTree() {
	root = nullptr;
	node_count = 0;
}
BasicTree::~BasicTree() {
	destroy(root);
}
void BasicTree::destroy(Node* node) {
	if (!node) return;
	destroy(node->left);
	destroy(node->right);
	delete node;
}

