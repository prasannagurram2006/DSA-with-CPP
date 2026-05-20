#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = NULL;
    }
};

bool hasCycle(ListNode* head) {

    ListNode* slow = head; // slow moves 1 step
    ListNode* fast = head; // fast moves 2 steps

    // no cycle -> fast reaches NULL
    // cycle exists -> fast meets slow
    while(fast != NULL && fast->next != NULL) {

        slow = slow->next; // move slow by 1
        fast = fast->next->next; // move fast by 2

        // if both meet -> cycle exists
        if(slow == fast) {
            return true;
        }
    }

    // fast reached NULL -> no cycle
    return false;
}

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if(n == 0) return 0;

    cout << "Enter node values:\n";

    int val;
    cin >> val;

    ListNode* head = new ListNode(val);
    ListNode* temp = head;

    // create linked list
    for(int i = 1; i < n; i++) {

        cin >> val;

        temp->next = new ListNode(val);

        temp = temp->next;
    }

    /*
    Enter cycle position:

    Example:
    1

    tail connects to node at index 1

    Enter -1 for no cycle
    */

    int pos;
    cout << "Enter cycle position (-1 for no cycle): ";
    cin >> pos;

    // create cycle
    if(pos != -1) {

        ListNode* cycleNode = head;
        ListNode* tail = head;

        // move to cycle position
        for(int i = 0; i < pos; i++) {
            cycleNode = cycleNode->next;
        }
        // move to last node
        while(tail->next != NULL) {
            tail = tail->next;
        }

        // connect tail to cycle node
        tail->next = cycleNode;
    }

    if(hasCycle(head)) {
        cout << "Cycle detected";
    }
    else {
        cout << "No cycle";
    }

    return 0;
}