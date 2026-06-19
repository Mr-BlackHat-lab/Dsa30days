#pragma once

#include <vector>

class LinearProbing {
private:
	std::vector <int> buckets;
	int bucketsize;
	float load_factor;
	int data_count;
public:
	LinearProbing(int size);
	~LinearProbing();
	bool isEmpty() const;
	bool search(int value) const;
	int hashFucnction(int value);
	void reshape();
	void reshape_caller();
	void insert(int value);
	void remove(int value);
	void traver();
};
