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
		std::cout << "Value:"<<value<<" already exist in tree\n";
		return;
	}
	root = insertHelper(root, value);
	std::cout << "value:" << value << " is sucssefully pushed\n";
	node_count++;
}
void BinaryTree::peek_root() const {
	if (!isEmpty()) {
		std::cout << "Root value:" << root->data << " \n";
		return;
	}
	std::cout<<"Tree is Empty\n";
}
Node* BinaryTree::removeHelper(Node* node, int value) {

	if (node == nullptr) return nullptr;//it wont come here any case because i alerady checked if value exist in tree using search

	if (value < node->data) {
		node->left = removeHelper(node->left, value);
	}
	else if (value > node->data) {
		node->right = removeHelper(node->right, value);
	}

	else {
		// CASE 1: Leaf (0 children)
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node_count--;
			return nullptr;
		}

		// CASE 2: 1 child
		else if (node->left == nullptr) {
			Node* temp = node->right;
			delete node;
			node_count--;
			return temp; // Return the right child up to the parent
		}
		else if (node->right == nullptr) {
			Node* temp = node->left;
			delete node;
			node_count--;
			return temp; // Return the left child up to the parent
		}

		// CASE 3: 2 children (node->left != nullptr && node->right != nullptr)
		else {
			Node* temp = node->right;
			while (temp->left != nullptr) { temp = temp->left; }
			node->data = temp->data;
			node->right = removeHelper(node->right, temp->data);
		}

	}

	return node;
}
void BinaryTree::remove(int value) {
	if (!search(value)) {
		std::cout << "Value:" << value << " dosen't exists in tree\n";
		return;
	}
	root = removeHelper(root, value);
	std::cout << "value:" << value << " has been removed\n";
}

int BinaryTree::heightHelper(Node* node) const {
	if (node == nullptr) return 0;
	int left_height = heightHelper(node->left);
	int right_height = heightHelper(node->right);
	return std::max(left_height, right_height) + 1;
}
int BinaryTree::treeHeight() const {
	return heightHelper(root);
}


void BinaryTree::preOrderHelper(Node* node) const {
	if (node == nullptr)return;
	std::cout << node->data << " ";
	preOrderHelper(node->left);
	preOrderHelper(node->right);
}
void BinaryTree::traversePreOrder() const {
	preOrderHelper(root);
	std::cout << "\n";
}


void BinaryTree::inOrderHelper(Node* node) const {
	if (node == nullptr)return;
	inOrderHelper(node->left);
	std::cout << node->data << " ";
	inOrderHelper(node->right);
}
void BinaryTree::traverseInOrder() const {
	inOrderHelper(root);
	std::cout << "\n";
}


void BinaryTree::postOrderHelper(Node* node) const {
	if (node == nullptr)return;
	postOrderHelper(node->left);
	postOrderHelper(node->right);
	std::cout << node->data << " ";
}
void BinaryTree::traversePostOrder() const {
	postOrderHelper(root);
	std::cout << "\n";
}

