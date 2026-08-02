#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int x = 0;
        int y = 0;
        int ans = 0;

        for (int start = 0; start < nums.size(); start++) {
            for (int end = start; end < nums.size(); end++) {

                if (nums[end] % 2 == 0) {
                    x++;
                } else {
                    y++;
                }

                if (y > 0 && ((x * b) <= (y * a))) {
                    ans++;
                }
            }

            x = 0;
            y = 0;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;

    int result = obj.countRatioSubarrays(nums, a, b);

    cout << "Answer = " << result << endl;

    return 0;
}
//intuition for this approach is 
//start ptr starts a new subarray end grows it one element
//so count even odd i.e x and y for every newly added element
//and comp with cond given
//if yes increase ans by one
//for every start reset x and y counts to 0
//so this code tc is O(n^2)

// You are given an integer array nums and two integers a and b.

// For a subarray, let:

// x be the number of even elements.
// y be the number of odd elements.
// The ratio of even to odd elements in a subarray is defined as x / y, where ratios are compared by their exact rational values.

// A subarray is considered valid if:

// y > 0, and
// x / y <= a / b.
// Return the number of valid subarrays in nums.

 

// Example 1:

// Input: nums = [1,2,1,2], a = 3, b = 2

// Output: 7