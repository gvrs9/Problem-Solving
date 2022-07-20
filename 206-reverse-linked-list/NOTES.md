```
#include "iostream"
#include "typeinfo"
#define ln "\n"
#define lnBreak cout << "---------------\n"
using namespace std;
​
class Node {
public:
int data;
Node* next;
​
Node(int data) {
/*
(*this).data = data;
(*this).next = NULL;
*/
​
// or
​
this -> data = data;
this -> next = NULL;
}
​
~Node() {
int value = this -> data;
// memory free
if (this -> next != NULL) {
this -> next = NULL;
delete next;
}
cout << " memory is free for node with data " << value << endl;
}
};
​
void insertAtHead(Node* &head, int data) {
Node* newNode = new Node(data);
// cout << newNode -> data << ln;
newNode -> next = head;
head = newNode;
}
​
void insertAtTail(Node* &tail, int data) {
Node* newNode = new Node(data);