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
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;          // move 1 step
            fast = fast->next->next;   // move 2 steps

            // cycle found
            if(slow == fast) {

                slow = head; // one pointer to head

                // Step 2: Find cycle start
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow; // cycle starting node
            }
        }

        return NULL; // no cycle
    }
};

int main() {

    // Creating nodes
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Creating cycle
    fourth->next = second;

    Solution obj;

    ListNode* ans = obj.detectCycle(head);

    if(ans != NULL) {
        cout << "Cycle starts at node value: " << ans->val << endl;
    }
    else {
        cout << "No cycle present" << endl;
    }

    return 0;
}
/*1. Move slow and fast
2. If they meet:
       move slow to head
3. Move both one step
4. Where they meet again = cycle start
5. return that node
6. If loop ends -> return NULL*/
/*distance from HEAD to cycle start
=
distance from MEETING POINT to cycle start*/