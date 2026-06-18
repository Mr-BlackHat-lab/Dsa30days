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
float HashMap::load_factor_calculator_runner() {
	load_factor = (float)data_count/bucketCount;
	if (load_factor >= 0.75) {
		std::cout << "load factor: "<<load_factor<<" is larger than the set value so resize the Hashmap\n";
		resizer();
	}
	return load_factor;
}
void HashMap::resizer() {
	std::vector<int> tempData;

	for (int i = 0; i < buckets.size(); i++) {
		Node* head = buckets[i];

		while (head != nullptr) {
			tempData.push_back(head->data);
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		// CRITICAL: Reset the bucket to nullptr so it's truly empty
		buckets[i] = nullptr;
	}
	buckets.resize(bucketCount * 2, nullptr);
	bucketCount = bucketCount * 2; // for future resize;
	data_count = 0;
	for (int val:tempData) {
		insert(val);
	}
	std::cout << "--> Rehash triggered! Capacity expanded to " << bucketCount << "\n";
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

	Node* temp = buckets[index];
	newNode->next = temp;
	buckets[index] = newNode;
	std::cout << "Succssefully! insert the value :" << value << " in HashMap\n";
	data_count++;
	load_factor_calculator_runner();



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
		data_count--;
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
			data_count--;
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