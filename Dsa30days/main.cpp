#include <iostream>

#include "MaxHeap.h"
//#include "AvlTree.h"
//#include "BinaryTree.h"
//#include "BasicTree.h"
//#include "LinearProbing.h"
//#include "HashMap.h"
//#include "ArrayStack.h"
//#include "LinkedlistStack.h"
//#include "ArrayQueue.h"
//#include "LinkedListQueue.h"
//#include "LinkListBTree.h"
using namespace std;
int main()
{
    MaxHeap heap;

    std::cout << "--- 1. Testing Insert (Bubbling Up) ---\n";
    // Let's insert random, unordered numbers
    heap.insert(10);
    heap.insert(30);
    heap.insert(20);
    heap.insert(50);
    heap.insert(40);
    heap.insert(15);

    std::cout << "Heap Array (Level-Order Traversal): ";
    heap.printHeap();
    // Expected output: 50 40 20 10 30 15 
    // Notice how 50 fought its way to index 0!

    std::cout << "\nThe absolute Maximum value is currently: " << heap.peekMax() << "\n";
    std::cout << "Total elements in heap: " << heap.getSize() << "\n\n";

    std::cout << "--- 2. Testing Extract Max (Heap Sort) ---\n";
    std::cout << "Extracting values one by one:\n";

    // We will pull the King off the top until the heap is empty
    while (!heap.isEmpty()) {
        std::cout << heap.extractMax() << " ";
    }
    std::cout << "\n";
    // Expected output: 50 40 30 20 15 10 (Perfectly sorted from highest to lowest!)

    return 0;

    //AvlTree tree;
    //cout << "--- 1. Testing AVL Tree Insertions ---\n";
    //// Insert values that will trigger rotations
    //tree.insert(50);
    //tree.insert(25);
    //tree.insert(75);
    //tree.insert(10);
    //tree.insert(30);
    //tree.insert(60);
    //tree.insert(80);
    //tree.insert(5);
    //tree.insert(15);
    //cout << "Inserted: 50, 25, 75, 10, 30, 60, 80, 5, 15\n";
    //cout << "\n--- 2. Testing Tree Info ---\n";
    //tree.peek_root();
    //tree.tree_height();
    //cout << "\n--- 3. Testing Traversals (Self-Balancing Verification) ---\n";
    //tree.in_orderTraversal();   // Should print sorted order
    //tree.pre_orderTraversal();  // Root first
    //tree.post_orderTraversal(); // Root last
    //cout << "\n--- 4. Testing AVL Search ---\n";
    //if (tree.search(30)) {
    //    cout << "Success! Found 30 in the AVL tree.\n";
    //}
    //if (tree.search(60)) {
    //    cout << "Success! Found 60 in the AVL tree.\n";
    //}
    //if (!tree.search(99)) {
    //    cout << "Success! 99 was correctly NOT found.\n";
    //}
    //cout << "\n--- 5. Testing AVL Deletions (With Rebalancing) ---\n";
    //cout << "> Removing 5 (Leaf Node)...\n";
    //tree.remove(5);
    //tree.in_orderTraversal();
    //cout << "\n> Removing 10 (One Child)...\n";
    //tree.remove(10);
    //tree.in_orderTraversal();
    //cout << "\n> Removing 25 (Two Children)...\n";
    //tree.remove(25);
    //tree.in_orderTraversal();
    //cout << "\n--- 6. Post-Deletion Tree Info ---\n";
    //tree.peek_root();
    //tree.tree_height();
    //tree.in_orderTraversal();
    //cout << "\n--- 7. Testing Empty Tree Operations ---\n";
    //AvlTree emptyTree;
    //if (emptyTree.isEmpty()) {
    //    cout << "Empty tree confirmed as empty.\n";
    //}
    //emptyTree.peek_root();
    //emptyTree.tree_height();
    //emptyTree.in_orderTraversal();
 

    // BinaryTree tree;
    // std::cout << "--- 1. Testing BST Insertions ---\n";
    // // This will build the following Binary Search Tree:
    // //             50
    // //           /    \
    // //         30      70
    // //        /  \    /  \
    // //      20   40  60   80
    // //          /
    // //        35
    // tree.insert(50); // Root
    // tree.insert(30);
    // tree.insert(70);
    // tree.insert(20);
    // tree.insert(40);
    // tree.insert(60);
    // tree.insert(80);
    // tree.insert(35);
    // std::cout << "\n--- 2. Testing Traversals (The Magic of BST) ---\n";
    // // If the BST rules are working, In-Order MUST print in perfectly sorted ascending order!
    // std::cout << "In-Order   (Expected: 20 30 35 40 50 60 70 80): \n";
    // tree.traverseInOrder();
    // std::cout << "Pre-Order  (Expected: 50 30 20 40 35 70 60 80): \n";
    // tree.traversePreOrder();
    // std::cout << "Post-Order (Expected: 20 35 40 30 60 80 70 50): \n";
    // tree.traversePostOrder();
    // std::cout << "\n--- 3. Testing Tree Info ---\n";
    // std::cout << "Tree Height (Expected: 4): " << tree.treeHeight() << "\n";
    // tree.peek_root(); // Should be 50
    // std::cout << "\n--- 4. Testing BST Search ---\n";
    // if (tree.search(60)) {
    //     std::cout << "Success! Found 60 in the tree.\n";
    // }
    // if (!tree.search(99)) {
    //     std::cout << "Success! 99 was correctly NOT found.\n";
    // }
    // std::cout << "\n--- 5. Testing 'Hibbard Deletion' (All 3 Cases) ---\n";
    // std::cout << "> Case 1 (Leaf Node): Removing 20...\n";
    // tree.remove(20);
    // std::cout << "> Case 2 (One Child): Removing 40 (Has left child 35)...\n";
    // tree.remove(40);
    // std::cout << "> Case 3 (Two Children): Removing Root 50...\n";
    // // The successor of 50 is 60 (smallest on the right side). 
    // // 60 should steal 50's data, and the original 60 node should be deleted!
    // tree.remove(50);
    // std::cout << "\n--- 6. Post-Deletion Verification ---\n";
    // std::cout << "In-Order   (Expected: 30 35 60 70 80): \n";
    // tree.traverseInOrder();
    // std::cout << "Root after deleting 50 (Expected: 60):\n";
    // tree.peek_root();


    //BasicTree tree;
    //std::cout << "--- 1. Testing Complete Tree Insertions (BFS) ---\n";
    //// This will build a perfectly balanced complete tree:
    ////         1
    ////       /   \
    ////      2     3
    ////     / \   / \
    ////    4   5 6   7
    //tree.insert(1); // Root
    //tree.insert(2); // Left of 1
    //tree.insert(3); // Right of 1
    //tree.insert(4); // Left of 2
    //tree.insert(5); // Right of 2
    //tree.insert(6); // Left of 3
    //tree.insert(7); // Right of 3
    //std::cout << "\n--- 2. Testing Recursive Traversals ---\n";
    //std::cout << "Pre-Order  (Expected: 1 2 4 5 3 6 7): \n";
    //tree.traversePreOrder();
    //std::cout << "In-Order   (Expected: 4 2 5 1 6 3 7): \n";
    //tree.traverseInOrder();
    //std::cout << "Post-Order (Expected: 4 5 2 6 7 3 1): \n";
    //tree.traversePostOrder();
    //std::cout << "\n--- 3. Testing Tree Info ---\n";
    //std::cout << "Tree Height (Expected: 3): " << tree.treeHeight() << "\n";
    //tree.peek_root();
    //std::cout << "\n--- 4. Testing BFS Search ---\n";
    //if (tree.search(5)) {
    //    std::cout << "Success! Found 5 in the tree.\n";
    //}
    //if (!tree.search(99)) {
    //    std::cout << "Success! 99 was correctly NOT found.\n";
    //}
    //std::cout << "\n--- 5. Testing 'Swap with Last Node' Deletion ---\n";
    //// The last node inserted was 7. 
    //// If we delete 2, the value 7 should overwrite 2, and the physical node 7 should disappear.
    //// New Tree structure should look like this:
    ////         1
    ////       /   \
    ////      7     3
    ////     / \   / 
    ////    4   5 6   
    //tree.remove(2);
    //std::cout << "\n--- 6. Post-Deletion Verification ---\n";
    //std::cout << "In-Order   (Expected: 4 7 5 1 6 3): \n";
    //tree.traverseInOrder();
    //std::cout << "Tree Height (Expected: 3): " << tree.treeHeight() << "\n";
    //// Deleting the root (1) should replace it with the new last node (6)
    //tree.remove(1);
    //std::cout << "Root after deleting 1:\n";
    //tree.peek_root(); // Should be 6!

    //LinearProbing lp(5);
    //std::cout << "--- 1. Testing Insertions and Collisions ---\n";
    //// Assuming size 5, these will all hash to index 0, forcing a probe chain
    //lp.insert(5);  // Goes to 0
    //lp.insert(10); // Collides at 0, probes to 1
    //lp.insert(15); // Collides at 0 & 1, probes to 2
    //std::cout << "\n--- 2. Testing Tombstones (Lazy Deletion) ---\n";
    //lp.remove(10); // Deletes 10 (at index 1), turning it into a Tombstone
    //// If tombstones work, searching for 15 will skip over index 1 and still find it at index 2!
    //if (lp.search(15)) {
    //    std::cout << "Success: 15 was found despite the Tombstone!\n";
    //}
    //else {
    //    std::cout << "Fail: Tombstone broke the search chain!\n";
    //}
    //std::cout << "\n--- 3. Viewing the State ---\n";
    //lp.traver();

    //HashMap myMap(5);
    //cout << "--- 1. Testing Insertions (Forcing Collisions) ---\n";
    //myMap.insert(5);
    //myMap.insert(15); // Will collide with 5
    //myMap.insert(25); // Will collide with 5 and 15
    //myMap.insert(42); // Will go to bucket 2
    //myMap.insert(42); // Testing your duplicate check
    //cout << "\n--- 2. Viewing the Hash Map ---\n";
    //myMap.view();
    //cout << "\n--- 3. Testing Search ---\n";
    //if (myMap.search(15)) {
    //    cout << "Success: 15 was found in the map!\n";
    //}
    //else {
    //    cout << "Error: 15 is missing!\n";
    //}
    //cout << "\n--- 4. Testing Removal ---\n";
    //myMap.remove(15); // Removing a middle node from the chain
    //myMap.remove(99); // Testing removal of a non-existent value
    //cout << "\n--- 5. Final Hash Map State ---\n";
    //myMap.view();

    //ArrayStack mystack(9);
    //mystack.push(4);
    //mystack.push(2);
    //mystack.push(2);
    //mystack.push(2);
    //mystack.push(1);
    //mystack.push(3);
    //mystack.push(0);
    //mystack.push(5);
    //if (mystack.isEmpty()) {
    //    cout << "stack is empty\n";
    //}
    //else {
    //    cout << "stack is not empty\n";
    //}
    //mystack.push(6);
    //mystack.push(4);
    //mystack.push(4);
    //mystack.pop();
    //cout << mystack.peek() << " is in top\n";
    //mystack.push(2);
    //mystack.push(1);
    //mystack.push(9);
    //mystack.push(8);
    //mystack.push(3);
    //mystack.push(5);
    //mystack.push(7);
    //if (mystack.isEmpty()) {
    //    cout << "stack is empty\n";
    //}
    //else {
    //    cout << "stack is not empty\n";
    //}
    //mystack.trav();
    //mystack.CountingSort(0, 5);
    //mystack.trav();
    //mystack.pop();

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