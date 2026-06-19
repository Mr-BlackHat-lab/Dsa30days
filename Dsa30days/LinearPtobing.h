#pragma once

#include <vector>

class LinearProbing {
private:
	std::vector <int> buckets;
	int bucketsize;
	int load_factor;
	int data_count;
public:
	LinearProbing();
	~LinearProbing();
	bool isEmpty() const;
	bool search(int value) const;
	int hashFucnction(int value);
	void reshape();
	void insert(int value);
	void remove(int value);
	void traver();
};
