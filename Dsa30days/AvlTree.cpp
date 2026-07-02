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
Node* AvlTree::insertHelper(Node* node, int value) {
	if (!node) {
		Node* newNode = new Node;
		newNode->data = value;
		newNode->left = newNode->right = nullptr;
		newNode->height = 1;
		return newNode;
	}


	if (value < node->data) {
		node->left = insertHelper(node->left, value);
	}
	else if (value > node->data) {
		node->right = insertHelper(node->right, value);
	}
	else {
		return node; // Duplicate values not allowed, just return the node
	}


	node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;


	int balance = getBalanceFactor(node);
	if (balance > 1 && value < node->left->data) {// ll case
		return rightRotate(node);
	}
	if (balance < -1 && value > node->right->data) {// rr case
		return leftRotate(node);
	}
	if (balance > 1 && value > node->left->data) {// lr case
		node->left = leftRotate(node->left); // converting from lr to ll
		return rightRotate(node);
	}
	if (balance < -1 && value < node->right->data) {// rl case
		node->right = rightRotate(node->right); // converting from rl to rr
		return leftRotate(node);
	}
	return node;
}

Node* AvlTree::removeHelper(Node* node, int value) {
	if (!node) return nullptr;

	if (value < node->data) {
		node->left = removeHelper(node->left, value);
	}
	else if (value > node->data) {
		node->right = removeHelper(node->right, value);
	}
	else {
		// Node to be deleted found
		if (!node->left && !node->right) {
			delete node;
			return nullptr;
		}
		if (!node->left) {
			Node* temp = node->right;
			delete node;
			return temp;
		}
		if (!node->right) {
			Node* temp = node->left;
			delete node;
			return temp;
		}

		// Node with two children: get the inorder successor
		Node* temp = node->right;
		while (temp->left) {
			temp = temp->left;
		}
		node->data = temp->data;
		node->right = removeHelper(node->right, temp->data);
	}

	if (!node) return nullptr;

	node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
	int balance = getBalanceFactor(node);

	// Left Left Case
	if (balance > 1 && getBalanceFactor(node->left) >= 0) {
		return rightRotate(node);
	}
	// Left Right Case
	if (balance > 1 && getBalanceFactor(node->left) < 0) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	// Right Right Case
	if (balance < -1 && getBalanceFactor(node->right) <= 0) {
		return leftRotate(node);
	}
	// Right Left Case
	if (balance < -1 && getBalanceFactor(node->right) > 0) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

int AvlTree::treeheightHelper(Node* node) const {
	if (!node) return 0;
	return std::max(treeheightHelper(node->left), treeheightHelper(node->right)) + 1;
}

void AvlTree::preorderHelper(Node* node) const {
	if (!node) return;
	std::cout << node->data << " ";
	preorderHelper(node->left);
	preorderHelper(node->right);
}

void AvlTree::postorderHelper(Node* node) const {
	if (!node) return;
	postorderHelper(node->left);
	postorderHelper(node->right);
	std::cout << node->data << " ";
}

void AvlTree::inorderHelper(Node* node) const {
	if (!node) return;
	inorderHelper(node->left);
	std::cout << node->data << " ";
	inorderHelper(node->right);
}

bool AvlTree::isEmpty() const {
	return root == nullptr;
}

bool AvlTree::search(int value) const {
	Node* temp = root;
	while (temp) {
		if (value == temp->data) {
			return true;
		}
		else if (value < temp->data) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	return false;
}

void AvlTree::insert(int value) {
	root = insertHelper(root, value);
	node_count++;
}

void AvlTree::remove(int value) {
	if (search(value)) {
		root = removeHelper(root, value);
		node_count--;
	}
}

void AvlTree::peek_root() const {
	if (!root) {
		std::cout << "Tree is empty" << std::endl;
	}
	else {
		std::cout << "Root value: " << root->data << std::endl;
	}
}

void AvlTree::tree_height() const {
	std::cout << "Tree height: " << treeheightHelper(root) << std::endl;
}

void AvlTree::pre_orderTraversal() const {
	if (isEmpty()) {
		std::cout << "Tree is empty" << std::endl;
		return;
	}
	std::cout << "Preorder Traversal: ";
	preorderHelper(root);
	std::cout << std::endl;
}

void AvlTree::post_orderTraversal() const {
	if (isEmpty()) {
		std::cout << "Tree is empty" << std::endl;
		return;
	}
	std::cout << "Postorder Traversal: ";
	postorderHelper(root);
	std::cout << std::endl;
}

void AvlTree::in_orderTraversal() const {
	if (isEmpty()) {
		std::cout << "Tree is empty" << std::endl;
		return;
	}
	std::cout << "Inorder Traversal: ";
	inorderHelper(root);
	std::cout << std::endl;
}