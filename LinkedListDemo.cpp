#include "LinkedList.cpp"

int main() {
    LinkedList list1;
    cout << "First Linked List:  \n";
    list1.insertAtBeginning(1);
    list1.insertAtBeginning(2);
    list1.insertAtBeginning(3);
    list1.print();

    LinkedList list2;
    cout << "Second Linked List:  \n";
    list2.insertAtEnd(4);
    list2.insertAtEnd(5);
    list2.insertAtEnd(6);
    list2.print();

    list1.concatenate(list2);
    cout << "Concatenated Linked List:  \n";
    list1.print();

    list1.insertAfterKey(3, 7);
    cout << "Insertion after key = 3";
    list1.print();
    list1.insertBeforeKey(7, 8);
    cout<<"Insertion before Key=7:\n";
    list1.print();

    list1.deleteFromBeginning();
    cout << "Deleting from Beginning:\n";
    list1.print();
    list1.deleteFromEnd();
    cout << "Deleting from End:\n";
    list1.print();
    list1.deleteAfterKey(2);
    cout << "Deleting After Key=2:\n";
    list1.print();

    cout << "Search for 5: \n" << (list1.search(5) ? "Found" : "Not Found") << endl;

    list1.reverse();
    cout << "Reversed Linked List: \n";
    list1.print();

    cout << "Reverse traversal: \n";
    list1.reverseTraversal();

    list1.sort();
    cout << "Sorted Linked List: \n";
    list1.print();

    return 0;
}
