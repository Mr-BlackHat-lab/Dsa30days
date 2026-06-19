#include <vector>
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
			while (buckets[index] == -1 && index < bucketsize) {
				if (buckets[index] == value) {
					return true;
				}
				index++;
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
	buckets.resize(bucketsize, -1);//bucketsize increase in reshape_caller befor calling it & data_count = 0 also
	for (int val : tempVector) {
		insert(val);
	}
	tempVector.clear();
}
void LinearProbing::reshape_caller() {

}