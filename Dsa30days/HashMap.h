#pragma once
#include <vector>
struct Node
{
	int data;
	Node* next;
};
class HashMap {
private:
	std::vector <Node*> buckets;
	int hashFunctionMod(int value) const;
public:
	HashMap(int bucketCount);
	~HashMap();
	void insert(int value);
	bool search(int value) const;
	bool isEmpty() const;
	void remove(int value);
};