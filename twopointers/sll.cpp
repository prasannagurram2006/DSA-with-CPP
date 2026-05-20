#include <iostream>
using namespace std;


/*
=============================
SINGLY LINKED LIST (SLL)
=============================

Each node contains:
1. data
2. address of next node

Example:

10 -> 20 -> 30 -> NULL
*/


// Node structure
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int val) {
        data = val;
        next = NULL;
    }
};



// ==============================
// INSERT AT END
// ==============================
/*
Adds new node at last.

Example:

10 -> 20 -> NULL

Insert 30

10 -> 20 -> 30 -> NULL
*/

void insertAtEnd(Node* &head, int val) {

    // create new node
    Node* newNode = new Node(val);

    // if linked list is empty
    if(head == NULL) {
        head = newNode;
        return;
    }

    // temp used for traversal
    Node* temp = head;

    // move till last node
    while(temp->next != NULL) {
        temp = temp->next;
    }

    // connect last node to new node
    temp->next = newNode;
}



// ==============================
// INSERT AT BEGINNING
// ==============================
/*
New node becomes first node.

Example:

10 -> 20 -> 30

Insert 5

5 -> 10 -> 20 -> 30
*/

void insertAtBeginning(Node* &head, int val) {

    // create new node
    Node* newNode = new Node(val);

    // new node points to current head
    newNode->next = head;

    // move head to new node
    head = newNode;
}



// ==============================
// DELETE FIRST NODE
// ==============================
/*
Deletes first node.

Example:

10 -> 20 -> 30

After delete:

20 -> 30
*/

void deleteFirst(Node* &head) {

    // if list is empty
    if(head == NULL) {
        return;
    }

    // store current head
    Node* temp = head;

    // move head forward
    head = head->next;

    // delete old first node
    delete temp;
}



// ==============================
// TRAVERSAL / PRINTING
// ==============================
/*
Traversal means visiting every node.

Logic:
start from head
↓
print node
↓
move to next node
*/

void printList(Node* head) {

    // temp used for traversal
    Node* temp = head;

    while(temp != NULL) {

        cout << temp->data << " -> ";

        // move to next node
        temp = temp->next;
    }

    cout << "NULL";
}




int main() {

    /*
    USER INPUT

    Enter number of nodes.

    Example:
    4

    Means linked list will contain 4 nodes.
    */

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;


    /*
    Enter node values.

    Example:
    10 20 30 40

    Linked list becomes:

    10 -> 20 -> 30 -> 40 -> NULL
    */

    cout << "Enter node values:\n";

    for(int i = 0; i < n; i++) {

        int val;
        cin >> val;

        // insert each value at end
        insertAtEnd(head, val);
    }


    cout << "\nOriginal Linked List:\n";
    printList(head);



    /*
    INSERT AT BEGINNING
    */

    int beginValue;

    cout << "\n\nEnter value to insert at beginning: ";
    cin >> beginValue;

    insertAtBeginning(head, beginValue);

    cout << "\nAfter inserting at beginning:\n";
    printList(head);



    /*
    INSERT AT END
    */

    int endValue;

    cout << "\n\nEnter value to insert at end: ";
    cin >> endValue;

    insertAtEnd(head, endValue);

    cout << "\nAfter inserting at end:\n";
    printList(head);



    /*
    DELETE FIRST NODE
    */

    deleteFirst(head);

    cout << "\n\nAfter deleting first node:\n";
    printList(head);


    return 0;
}