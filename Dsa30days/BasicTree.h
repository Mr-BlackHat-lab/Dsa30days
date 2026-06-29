#pragma once

struct Node
{
	int data;
	Node* parent;
	Node* left;
	Node* right;
};
class BasicTree {
private:
	Node* root;
	int node_count;
	void destroy(Node* node); //done
public:
	
	BasicTree();//done
	~BasicTree();//done

	bool isEmpty() const;//done

	//core operation
    void insert(int value);//done
    void remove(int value);//done
    bool search(int value) const;//done

    // Utilities
    void peek_root() const;//done
    int treeHeight() const;

    // Trees have 3 distinct ways to traverse!
    void traverseInOrder() const;
    void traversePreOrder() const;
    void traversePostOrder() const;
};