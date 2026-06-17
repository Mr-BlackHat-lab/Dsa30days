#pragma once
#include <vector>
struct Node
{
	int data;
	Node* next;
};
class HashMap {
private:
	int bucketCount;
	std::vector <Node*> buckets;//done
	int hashFunctionMod(int value) const; //done
public:
	HashMap(int size); //done
	~HashMap(); //done
	void insert(int value);//done
	bool search(int value) const;//done
	bool isEmpty() const; //done
	void remove(int value);//done
	void view() const;
};