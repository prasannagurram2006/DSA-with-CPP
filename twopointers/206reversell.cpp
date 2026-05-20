#include <iostream>
using namespace std;
/*Store next node first
↓
Reverse current link
↓
Move prev ahead
↓
Move curr ahead*/

class ListNode {
public:
    int data;
    ListNode* next;

    // Constructor to create a node
    ListNode(int val) {
        data = val;
        next = NULL;
    }
};


// Function to reverse linked list
ListNode* reverseList(ListNode* head) {

    // prev initially points to nothing
    ListNode* prev = NULL;

    // curr starts from head
    ListNode* curr = head;

    // used to store next node temporarily
    ListNode* nextNode = NULL;

    while(curr != NULL) {

        // save next node
        // otherwise remaining list will be lost
        nextNode = curr->next;

        // reverse current node link
        curr->next = prev;

        // move prev one step ahead
        prev = curr;

        // move curr one step ahead
        curr = nextNode;
    }

    // prev becomes new head after reversal
    return prev;
}


// Function to print linked list
void printList(ListNode* head) {

    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL";
}


int main() {

   

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;


    // if user enters 0
    // linked list will be empty
    if(n == 0) {
        return 0;
    }


   
    int val;

    // create first node
    cout<<"enter value";
    cin >> val;

    ListNode* head = new ListNode(val);

    // temp used to build linked list
    ListNode* temp = head;
    // create remaining nodes
    for(int i = 1; i < n; i++) {

        cin >> val;

        // create new node and connect it
        temp->next = new ListNode(val);

        // move temp forward
        temp = temp->next;
    }


    cout << "\nOriginal Linked List:\n";
    printList(head);


    // reverse linked list
    head = reverseList(head);


    cout << "\n\nReversed Linked List:\n";
    printList(head);

    return 0;
}