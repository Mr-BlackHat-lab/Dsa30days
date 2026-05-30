#include <iostream>
#include "LinkListBTree.h"

LinkListBTree::LinkListBTree() {
	head = nullptr;
	nodes = 0;
}
LinkListBTree::~LinkListBTree() {
    destroy(head);
}
void LinkListBTree::destroy(Node* node) {
    if (!node) return;

    destroy(node->left);
    destroy(node->right);
    delete node;
}
void LinkListBTree::inorder(Node* node) const {
    if (node == nullptr)
        return;

    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}
void LinkListBTree::traversal() const {
    if (head == nullptr) {
        std::cout << "Tree is empty\n";
        return;
    }

    inorder(head);
    std::cout << '\n';
}
bool LinkListBTree::isEmpty() {
	return head == nullptr;
}
int LinkListBTree::peek_head() const {
    if (head == nullptr) {
        throw std::runtime_error("Tree is empty");
    }

    return head->data;
}
int LinkListBTree::tree_nodes() const {
    return nodes;
}
int LinkListBTree::height(Node* node) const {
    if (node == nullptr)
        return -1;   // height measured in edges

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return 1 + std::max(leftHeight, rightHeight);
}
int LinkListBTree::tree_height() const {
    return height(head);
}
void LinkListBTree::push(int value) {
	Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        nodes++;
        std::cout << value << " is pushed scussefully\n";
        return;
    }

    Node* temp = head;

    while (true) {
        if (value < temp->data) {
            if (temp->left == nullptr) {
                temp->left = newNode;
                newNode->prev = temp;
                break;
            }
            temp = temp->left;
        }
        else {
            if (temp->right == nullptr) {
                temp->right = newNode;
                newNode->prev = temp;
                break;
            }
            temp = temp->right;

        }
    }
    nodes++;
    std::cout << value << " is pushed scussefully\n";
}
