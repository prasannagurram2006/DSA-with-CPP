#include <iostream>
using namespace std;

class Solution {
public:

    // Function to generate next transformed number
    int nextNum(int n) {

        int sum = 0;

        while(n > 0) {

            int digit = n % 10;      // take last digit

            sum += digit * digit;    // add square of digit

            n = n / 10;              // remove last digit
        }

        return sum;
    }

    bool isHappy(int n) {

        // slow moves 1 step
        // fast moves 2 steps
        int slow = n;
        int fast = n;

        while(fast != 1) {

            slow = nextNum(slow);

            fast = nextNum(nextNum(fast));

            // cycle found
            if(slow == fast && slow != 1) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    int n;

    cout << "Enter number: ";
    cin >> n;

    Solution obj;

    if(obj.isHappy(n)) {
        cout << "Happy Number";
    }
    else {
        cout << "Not a Happy Number";
    }

    return 0;
}
// Happy Number Intuition

// 1. Every number generates another number
//    by sum of squares of digits
//    Example:
//    19 -> 82 -> 68 -> 100 -> 1

// 2. Only two things can happen:
//    a) sequence reaches 1  -> happy number
//    b) sequence repeats    -> cycle exists -> not happy

// 3. This behaves like linked list traversal:
//    current number -> next transformed number

// 4. Use Floyd Cycle Detection:
//    slow moves 1 step
//    fast moves 2 steps

// 5. If fast reaches 1:
//       return true

// 6. If slow == fast before reaching 1:
//       cycle found
//       return false
/*Repeated transformations can form a cycle.
Use slow-fast pointers to detect whether
sequence reaches 1 or loops forever.*/