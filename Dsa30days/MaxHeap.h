#pragma once

#include <vector>

class MaxHeap
{
public:
	MaxHeap();//done
	~MaxHeap();//done

	bool isEmpty() const;//done
	int getSize() const;//done

	void insert(int value);//done
	int extractMax();//remove and get biggest value in max queue(done)
	int peekMax() const;//done

	void printHeap() const;//done


private:
	std::vector<int> heap;

	int parent(int index) const; //done
	int leftChild(int index) const;// done
	int rightChild(int index) const;// done

	void heapifyUp(int index); //done
	void heapifyDown(int index);//done


};
