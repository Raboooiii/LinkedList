#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAfterKey(int key, int value);
    void insertBeforeKey(int key, int value);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteAfterKey(int key);
    void concatenate(LinkedList& list);
    bool search(int value);
    void reverse();
    void reverseTraversal();
    void sort();
    void print();
};
