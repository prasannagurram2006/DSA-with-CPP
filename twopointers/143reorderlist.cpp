#include <iostream>
using namespace std;

// Definition of singly linked list node
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:

    void reorderList(ListNode* head) {

        // if list has 0 or 1 node no need to reorder
        if(head == NULL || head->next == NULL) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle using slow-fast pointers
        while(fast->next != NULL && fast->next->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Start reversing from second half
        ListNode* curr = slow->next;

        // Break the list into 2 halves
        slow->next = NULL;

        ListNode* prev = NULL;
        ListNode* next = NULL;

        // Reverse second half using 3 pointers
        while(curr != NULL) {

            next = curr->next;   // save next node
            curr->next = prev;   // reverse link
            prev = curr;         // move prev ahead
            curr = next;         // move curr ahead
        }

        // first  -> first half
        // second -> reversed second half
        ListNode* first = head;
        ListNode* second = prev;

        ListNode* next1;
        ListNode* next2;

        // Merge both halves alternately
        while(second != NULL) {

            next1 = first->next;     // save next of first
            next2 = second->next;    // save next of second

            first->next = second;    // connect first -> second
            second->next = next1;    // connect second -> next1

            first = next1;           // move first ahead
            second = next2;          // move second ahead
        }
    }
};

// Function to print linked list
void printList(ListNode* head) {

    while(head != NULL) {

        cout << head->val;

        if(head->next != NULL) {
            cout << " ";
        }

        head = head->next;
    }
}

int main() {

    int n;
    cin >> n;

    // if empty list
    if(n == 0) {
        return 0;
    }

    int x;
    cin >> x;

    // create head node
    ListNode* head = new ListNode(x);

    ListNode* temp = head;

    // create remaining nodes
    for(int i = 1; i < n; i++) {

        cin >> x;

        temp->next = new ListNode(x);
        temp = temp->next;
    }

    Solution obj;

    obj.reorderList(head);

    // print reordered list
    printList(head);

    return 0;
}
/*Initially:

first  = 1 -> 2
second = 4 -> 3
Step 1

Save next nodes:

next1 = 2
next2 = 3

Connect:

1 -> 4

Then:

4 -> 2

List becomes:

1 -> 4 -> 2

Move pointers:

first = 2
second = 3
Step 2

Save next:

next1 = NULL
next2 = NULL

Connect:

2 -> 3

Final:

1 -> 4 -> 2 -> 3*/