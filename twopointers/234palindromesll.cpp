#include <iostream>
using namespace std;

// Definition for singly-linked list
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

    bool isPalindrome(ListNode* head) {

        // empty list or single node is always palindrome
        if(head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle using slow-fast pointers
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* curr = slow;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL) {

            next = curr->next;   // save next node
            curr->next = prev;   // reverse link
            prev = curr;         // move prev ahead
            curr = next;         // move curr ahead
        }

        // Compare first half and reversed second half
        ListNode* p1 = head;
        ListNode* p2 = prev;

        while(p2 != NULL) {

            if(p1->val != p2->val) {
                return false;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};

int main() {

    int n;
    cin >> n;

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

    if(obj.isPalindrome(head)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    return 0;
}