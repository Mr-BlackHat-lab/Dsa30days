#include <vector>
#include "LinearProbing.h"

LinearProbing::LinearProbing(int size) {
	bucketsize = size;
	buckets.resize(bucketsize);
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