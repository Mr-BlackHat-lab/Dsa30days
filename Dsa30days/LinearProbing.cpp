#include <vector>
#include <iostream>
#include "LinearProbing.h"

LinearProbing::LinearProbing(int size) {
	bucketsize = size;
	buckets.resize(bucketsize, -1);// 1.i am forced to set it default value to -1 i don't know how i can check if that index is clear or not because .empty() dose not work in int 2. if i need negative support also i can set it to INT64_MIN but dont know the default size of c++ like 32 or 64
	data_count = 0;
	load_factor = 0.0;
}
LinearProbing::~LinearProbing() {
		buckets.clear();
		//delete buckets;
		//buckets = nullptr;
		// i want to delete entier vector but don't know how to do that

}
int LinearProbing::hashFucnction(int value) {
	int index = value % bucketsize;
	return index;
}
bool LinearProbing::isEmpty() const{
	for (int val : buckets) {
		if (val != -1) {
			return false;
		}
	}
	return true;
}
bool LinearProbing::search(int value) {
	int index = hashFucnction(value);
	if (buckets[index]!= -1) {
		if (buckets[index] == value) {
			return true;
		}
		else {
			index++;
			while (buckets[index] == -1) {
				if (buckets[index] == value) {
					return true;
				}
				index++;
				if (index >= bucketsize) {
					index = 0;
				}
			}
		}
	}
	return false;
}
void LinearProbing::reshape() {
	std::vector <int> tempVector;
	for (int val : buckets) {
		if (val != -1) {
			tempVector.push_back(val);
		}
	}
	buckets.resize(bucketsize, -1);//bucketsize increase in reshape_caller befor calling it 
	data_count = 0;
	for (int val : tempVector) {
		insert(val);
	}
	tempVector.clear();
	std::cout << "reshape is sucssefully done new load_factor: " << float(data_count / bucketsize)<<"\n";
}
void LinearProbing::reshape_caller() { // call this after everytime you insert data 
	load_factor = float(data_count / bucketsize);
	if (load_factor > 0.5) {
		std::cout << "triggerd reshape because load factor:"<<load_factor<<" is greater than 0.5\n";
		bucketsize = bucketsize * 2;
		reshape();
	}

}
void LinearProbing::insert(int value) {
	int index = hashFucnction(value);

	while (buckets[index] != -1) {
		if (buckets[index] == value) {
			std::cout << "value:" << value << " already eixst!! duplicate value is not allowed\n";
			return;
		}
		index++;
		if (index >= bucketsize) {
			index = 0;
		}
	}
	buckets[index] = value;
	data_count+=1;
	std::cout << "value:"<<value<<" sucssesfully inserted\n";
}