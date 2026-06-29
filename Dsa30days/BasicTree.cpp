#include <iostream>
#include <stdexcept>
#include <queue>
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


void BasicTree::insert(int value) {
	Node* newNode = new Node();
	newNode->data = value;
	newNode->left = newNode->right =newNode->parent = nullptr;

	if (isEmpty()) {
		root = newNode;
		node_count++;
		std::cout << "value:"<<root->data<<" insert sucssesfully\n";
		return;
	}
	std::queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp->left == nullptr) {
			temp->left = newNode;
			newNode->parent = temp;
			node_count++;
			std::cout << "Value: " << value << " inserted successfully as LEFT child of " << temp->data << "\n";
			return;
		}
		else {
			q.push(temp->left);
		}
		if (temp->right == nullptr) {
			temp->right = newNode;
			newNode->parent = temp;
			node_count++;
			std::cout << "Value: " << value << " inserted successfully as LEFT child of " << temp->data << "\n";
			return;
		}
		else {
			q.push(temp->right);
		}
	}
}


void BasicTree::peek_root() const {
	if (!isEmpty()) {
		std::cout << "Root value:" << root->data << " \n";
		return;
	}
	throw std::runtime_error("Tree is Empty");
}

