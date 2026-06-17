#include <iostream>
#include "HashMap.h"
#include <vector>

HashMap::HashMap(int bucketCount) {
	buckets.resize(bucketCount, nullptr);
}
HashMap::~HashMap() {
	for (Node* head : buckets) {
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
}
int HashMap::hashFunctionMod(int value) const{
	return (value % 10);
}
bool HashMap::isEmpty() const {
	for (Node* head : buckets) {
		while (head) {
			return false;
		}
	}
	return true;
}