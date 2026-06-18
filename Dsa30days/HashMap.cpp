#include <iostream>
#include "HashMap.h"
#include <vector>

HashMap::HashMap(int size) {
	load_factor = 0;
	data_count = 0;
	bucketCount = size;
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
	return (value % bucketCount);
}
bool HashMap::isEmpty() const {
	for (Node* head : buckets) {
		while (head) {
			return false;
		}
	}
	return true;
	//buckets.empty(); i can use this but i like manual much better
}
bool HashMap::search(int value) const {
	int index = hashFunctionMod(value);
	if (buckets[index] == nullptr) {
		return false;
	}
	else {
		Node* temp = buckets[index];
		while (temp != nullptr) {
			if (temp->data == value) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
}
float HashMap::load_factor_calculator() {
	load_factor = bucketCount / data_count;
	return load_factor;
}
void HashMap::insert(int value){
	if (search(value)) {
		std::cout << "Error! the given value :"<<value<<" already exist in data\n";
		return;
	}
	
	Node* newNode = new Node();
	int index = hashFunctionMod(value);

	newNode->data = value;
	newNode->next = nullptr;
	load_factor_calculator();
	if (load_factor >= 2) {
		//resize the vector double it and re insert the data or call resize
	}

	Node* temp = buckets[index];
	newNode->next = temp;
	buckets[index] = newNode;
	std::cout << "Succssefully! insert the value :" << value << " in HashMap\n";
	data_count++;


	//insert at back 

	//if (buckets[index] == nullptr) {
	//	buckets[index] = newNode;
	//}
	//else {
		//Node* temp = buckets[index];
		//while(temp->next != nullptr) {
		//	temp = temp->next;
		//}
		//temp->next = newNode;

	//}

}
void HashMap::remove(int value) {

	int index = hashFunctionMod(value);

	if (buckets[index] == nullptr) {
		std::cout << "Error! The given value :" << value << " does not exist\n";
		return;
	}

	Node* temp = buckets[index];
	// Special case: removing the head node
	if (temp->data == value) {
		buckets[index] = temp->next;
		delete temp;

		std::cout << "Successfully removed the value :" << value << " in HashMap\n";
		return;
	}
	// Keep track of previous node so we can reconnect the list
	Node* prev = buckets[index];

	// Start searching from the second node
	temp = buckets[index]->next;

	while (temp != nullptr) {
		if (temp->data == value) {
			prev->next = temp->next;
			delete temp;

			std::cout << "Successfully removed the value :" << value << " in HashMap\n";
			return;
		}

		// Move both pointers forward
		// prev always stays one node behind temp
		prev = temp;
		temp = temp->next;
	}
	std::cout << "Error! The given value :" << value << " does not exist\n";
}
void HashMap::view() const {
	if (isEmpty()) {
		std::cout << "Erro! HashMap is Empty can't view";
		return;
	}
	int count = 0;
	for (Node* head : buckets) {
		std::cout << "Bucket " << count << ": ";
		while (head) {
			std::cout << head->data << " ";
			head = head->next;
		}
		std::cout << "\n";
		count++;
	}
}