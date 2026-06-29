#include <iostream>
#include <stdexcept>
#include <queue>
#include <algorithm>
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
	if (search(value)) {
		std::cout << "value:" << value << " already exist!! not inserted";
		return;
	}
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
void BasicTree::remove(int value) {

	if (!search(value)) {
		std::cout << "value:" << value << " not found";
		return;
	}
	Node* temp = root;
	if (temp->left == nullptr && temp->right == nullptr) {
		if (temp->data == value) {
			root = nullptr;
			node_count--;
			delete temp;
			std::cout << "value:" << value << " removed sucssesfully\n";
			return;
		}
	}

	std::queue<Node*> q;
	q.push(root);

	// i need two thing from this loop location of vlaue and last pushed node;
	Node* value_node = nullptr;
	Node* last_pushed_node = nullptr;


	while (!q.empty()) {
		temp = q.front();
		q.pop();
		last_pushed_node = temp;
		if (temp->data == value) {
			value_node = temp;
		}
		if (temp->left != nullptr) {
			q.push(temp->left);
		}
		if (temp->right != nullptr) {
			q.push(temp->right);
		}
	}
	value_node->data = last_pushed_node->data;
	temp = last_pushed_node->parent;
	if (temp->left == last_pushed_node) {
		temp->left = nullptr;
	}
	if (temp->right == last_pushed_node) {
		temp->right = nullptr;
	}
	node_count--;
	delete last_pushed_node;
	std::cout<< "value:" << value << " removed sucssesfully\n";

}

bool BasicTree::search(int value) const {
	if (isEmpty()) {
		return false;
	}
	std::queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();
		if (temp->data == value) {
			return true;
		}
		if (temp->left != nullptr) {
			q.push(temp->left);
		}
		if (temp->right != nullptr) {
			q.push(temp->right);
		}
	}
	return false;

}


void BasicTree::peek_root() const {
	if (!isEmpty()) {
		std::cout << "Root value:" << root->data << " \n";
		return;
	}
	throw std::runtime_error("Tree is Empty");
}

int BasicTree::heightHelper(Node* node) const {
	if (node == nullptr) return 0;
	int left_height = heightHelper(node->left);
	int right_height = heightHelper(node->right);
	return std::max(left_height, right_height) + 1;
}
int BasicTree::treeHeight() const {
	return heightHelper(root);
}


void BasicTree::preOrderHelper(Node* node) const{
	if (node == nullptr)return;
	std::cout << node->data<<" ";
	preOrderHelper(node->left);
	preOrderHelper(node->right);
}
void BasicTree::traversePreOrder() const {
	preOrderHelper(root);
	std::cout << "\n";
}


void BasicTree::inOrderHelper(Node* node) const {
	if (node == nullptr)return;
	inOrderHelper(node->left);
	std::cout << node->data << " ";
	inOrderHelper(node->right);
}
void BasicTree::traverseInOrder() const{
	inOrderHelper(root);
	std::cout << "\n";
}


void BasicTree::postOrderHelper(Node* node) const {
	if (node == nullptr)return;
	postOrderHelper(node->left);
	postOrderHelper(node->right);
	std::cout << node->data << " ";
}
void BasicTree::traversePostOrder() const {
	postOrderHelper(root);
	std::cout << "\n";
}

