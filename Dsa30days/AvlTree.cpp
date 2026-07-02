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
Node* AvlTree::rightRotate(Node* node) {

	Node* temp = node->left;
	Node* temp2 = temp->right;


	temp->right = node;
	node->left = temp2;

	node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
	temp->height = std::max(getHeight(temp->left), getHeight(temp->right)) + 1;

	return temp;
}

Node* AvlTree::leftRotate(Node* node) {

	Node* temp = node->right;
	Node* temp2 = temp->left;


	temp->left = node;
	node->right = temp2;


	node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
	temp->height = std::max(getHeight(temp->left), getHeight(temp->right)) + 1;


	return temp;
}