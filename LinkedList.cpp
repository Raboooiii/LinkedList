#include "LinkedList.h"

Node::Node(int value) {
    data = value;
    next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::insertAfterKey(int key, int value) {
    Node* newNode = new Node(value);
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        std::cout << "Key not found" << std::endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::insertBeforeKey(int key, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (head->data == key) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr) {
        std::cout << "Key not found" << std::endl;
        return;
    }
    prev->next = newNode;
    newNode->next = curr;
}

void LinkedList::deleteFromBeginning() {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::deleteFromEnd() {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* prev = nullptr;
    Node* curr = head;
    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }
    delete curr;
    prev->next = nullptr;
}

void LinkedList::deleteAfterKey(int key) {
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        std::cout << "Key not found or no element after key" << std::endl;
        return;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

void LinkedList::concatenate(LinkedList& list) {
    if (head == nullptr) {
        head = list.head;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = list.head;
    }
    list.head = nullptr;
}

bool LinkedList::search(int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void LinkedList::reverse() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void LinkedList::reverseTraversal() {
    reverse();
    print();
    reverse();
}

void LinkedList::sort() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;
    do {
        swapped = false;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void LinkedList::print() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
