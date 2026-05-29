#include <iostream>
#include "LinkedListQueue.h"

LinkedListQueue::LinkedListQueue() {
    head = nullptr;
    last = nullptr;
}

LinkedListQueue::~LinkedListQueue() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    last = nullptr;
}

bool LinkedListQueue::isEmpty() const {
    return head == nullptr;
}

int LinkedListQueue::peek_first() const {
    if (isEmpty()) {
        std::cout << "Error! Queue is empty\n";
        return -1;
    }

    return head->data;
}

int LinkedListQueue::peek_last() const {
    if (isEmpty()) {
        std::cout << "Error! Queue is empty\n";
        return -1;
    }

    return last->data;
}

void LinkedListQueue::traversal() const {
    if (isEmpty()) {
        std::cout << "Error! Queue is empty\n";
        return;
    }

    Node* temp = head;

    std::cout << "Traversing the queue\n";

    while (temp != nullptr) {
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
}

void LinkedListQueue::enqueue(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = last;
    if (isEmpty()) {
        head = last = newNode;
    }
    else {
        last->next = newNode;
        last = newNode;
    }
    std::cout << value << " enqueued successfully\n";
}

int LinkedListQueue::dequeue() {
    if (isEmpty()) {
        std::cout << "Error! Queue is empty\n";
        return -1;
    }

    Node* temp = head;
    int val = temp->data;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    else {
        last = nullptr;
    }
    delete temp;
    return val;
}