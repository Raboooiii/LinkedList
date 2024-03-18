#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int p);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void insertAtBeginning(int p);
    void insertAtEnd(int p);
    void insertAfterKey(int key, int p);
    void insertBeforeKey(int key, int p);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteAfterKey(int key);
    void concatenate(LinkedList& list);
    bool search(int p);
    void reverse();
    void reverseTraversal();
    void sort();
    void print();
};
