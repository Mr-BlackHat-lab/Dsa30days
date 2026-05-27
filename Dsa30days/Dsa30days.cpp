#include <iostream>

//#include "ArrayStack.h"
#include "LinkedlistStack.h"
using namespace std;
int main()
{
    //ArrayStack mystack(5);
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
    //mystack.trav();

    LinkedlistStack mystack;
    if (mystack.isEmpty()) {
        cout << "stack is empty\n";
    }
    else {
        cout << "stack is not empty\n";
    }
    mystack.push(20);
    mystack.push(30);
    mystack.push(40);
    mystack.pop();
    cout << mystack.peek() << " is in top\n";
    mystack.push(50);
    mystack.push(60);
    if (mystack.isEmpty()) {
        cout << "stack is empty\n";
    }
    else {
        cout << "stack is not empty\n";
    }
    mystack.traversal();
}
