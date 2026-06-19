#pragma once

#include <vector>

class LinearProbing {
private:
	std::vector <int> buckets;
	int bucketsize;
	float load_factor;
	int data_count;
public:
	LinearProbing(int size);//done
	~LinearProbing();//done
	bool isEmpty() const;// done
	bool search(int value);//done
	int hashFucnction(int value);//done
	void reshape();// done
	void reshape_caller();//done
	void insert(int value);//done
	void remove(int value);//done
	void traver() const;//done
};
