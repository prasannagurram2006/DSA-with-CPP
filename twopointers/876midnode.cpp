#include <iostream>
using namespace std;

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

    // Function to find middle node
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // fast moves 2 steps
        // slow moves 1 step
        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;          // 1 step
            fast = fast->next->next;   // 2 steps
        }

        // slow reaches middle
        return slow;
    }
};

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if(n == 0) {
        cout << "List is empty";
        return 0;
    }

    int value;

    // Create head node
    cout << "Enter value of node 1: ";
    cin >> value;

    ListNode* head = new ListNode(value);
    ListNode* temp = head;

    // Create remaining nodes
    for(int i = 2; i <= n; i++) {

        cout << "Enter value of node " << i << ": ";
        cin >> value;

        temp->next = new ListNode(value);
        temp = temp->next;
    }

    Solution obj;

    ListNode* middle = obj.middleNode(head);

    cout << "Middle node value is: " << middle->val;

    return 0;
}