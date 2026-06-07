#include <iostream>

#include "ArrayStack.h"
//#include "LinkedlistStack.h"
//#include "ArrayQueue.h"
//#include "LinkedListQueue.h"
//#include "LinkListBTree.h"
using namespace std;
int main()
{
    ArrayStack mystack(9);
    if (mystack.isEmpty()) {
        cout << "stack is empty\n";
    }
    else {
        cout << "stack is not empty\n";
    }
    mystack.push(6);
    mystack.push(4);
    mystack.push(4);
    mystack.pop();
    cout << mystack.peek() << " is in top\n";
    mystack.push(2);
    mystack.push(1);
    mystack.push(9);
    mystack.push(8);
    mystack.push(3);
    mystack.push(5);
    mystack.push(7);
    if (mystack.isEmpty()) {
        cout << "stack is empty\n";
    }
    else {
        cout << "stack is not empty\n";
    }
    mystack.trav();
    mystack.Mergesort();
    mystack.trav();
    mystack.pop();

    //LinkedlistStack mystack;
    //if (mystack.isEmpty()) {
    //    cout << "stack is empty\n";
    //}
    //else {
    //    cout << "stack is not empty\n";
    //}
    //mystack.push(20);
    //mystack.push(30);
    //mystack.push(40);
    //mystack.pop();
    //cout << mystack.peek() << " is in top\n";
    //mystack.push(50);
    //mystack.push(60);
    //if (mystack.isEmpty()) {
    //    cout << "stack is empty\n";
    //}
    //else {
    //    cout << "stack is not empty\n";
    //}
    //mystack.traversal();
    
    //ArrayQueue mystack(5);
    //for (int i = 1; i <= 5;i++) {
    //    mystack.push(i);
    //}
    //cout << mystack.peek_first() << " is going to poped\n";
    //cout << mystack.pop() << " is poped\n";
    //cout << mystack.peek_last() << " is last in line\n";
    //if (!mystack.isEmpty()) {
    //    cout << "queue is not empty\n";
    //}
    //mystack.traversal();
    //mystack.push(1);
    //mystack.traversal();

    //LinkedListQueue mystack;
    //for (int i = 1; i <= 5;i++) {
    //    mystack.enqueue(i);
    //}
    //cout << mystack.peek_first() << " is going to poped\n";
    //cout << mystack.dequeue() << " is poped\n";
    //cout << mystack.peek_last() << " is last in line\n";
    //if (!mystack.isEmpty()) {
    //    cout << "queue is not empty\n";
    //}
    //mystack.traversal();
    //mystack.enqueue(1);
    //mystack.traversal();


    // LinkListBTree myTree;

    //myTree.push(10);
    //myTree.push(5);
    //myTree.push(15);
    //myTree.push(3);
    //myTree.push(8);
    //myTree.push(12);
    //myTree.push(20);

    //cout << "\nTree Traversal (Inorder): ";
    //myTree.traversal();

    //cout << "\nRoot Node: " << myTree.peek_head() << endl;

    //cout << "Total Nodes: " << myTree.tree_nodes() << endl;

    //cout << "Tree Height: " << myTree.tree_height() << endl;

    //if (!myTree.isEmpty()) {
    //    cout << "Tree is not empty\n";
    //}


}
