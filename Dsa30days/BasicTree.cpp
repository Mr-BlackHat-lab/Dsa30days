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
bool BasicTree::isEmpty() const {
	return(root == nullptr);
}

void BasicTree::peek_root() const {
	if (!isEmpty()) {
		std::cout << "Root value:" << root->data << " \n";
		return;
	}
	throw std::runtime_error("Tree is Empty");
}

