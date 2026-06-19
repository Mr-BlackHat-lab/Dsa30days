#pragma once

#include <vector>
struct HashNode {
	int value = 0;
	bool is_empty = true;
	bool is_deleted = false;
};

class LinearProbing {
private:
	std::vector<HashNode> buckets;
	int bucketsize;
	float load_factor;
	int data_count;
public:
	LinearProbing(int size);//done
	~LinearProbing();//done
	bool isEmpty() const;// done
	bool search(int value);//done
	int hashFucntion(int value);//done
	void reshape();// done
	void reshape_caller();//done
	void insert(int value);//done
	void remove(int value);//done
	void traver() const;//done
};
