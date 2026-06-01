#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();

        // currMax -> maximum subarray sum ending at current index
        // maxSum  -> overall maximum subarray sum

        int currMax = nums[0];
        int maxSum = nums[0];

        // currMin -> minimum subarray sum ending at current index
        // minSum  -> overall minimum subarray sum

        int currMin = nums[0];
        int minSum = nums[0];

        for(int i = 1; i < n; i++) {

            /*
                For maximum sum:
                Either:
                1. Start new subarray from nums[i]
                2. Extend previous subarray
            */

            currMax = max(nums[i], currMax + nums[i]);

            // Update overall maximum
            maxSum = max(maxSum, currMax);

            /*
                For minimum sum:
                Either:
                1. Start new subarray from nums[i]
                2. Extend previous subarray
            */

            currMin = min(nums[i], currMin + nums[i]);

            // Update overall minimum
            minSum = min(minSum, currMin);
        }

        // Return larger absolute value
        return max(abs(maxSum), abs(minSum));
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements:\n";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    int ans = obj.maxAbsoluteSum(nums);

    cout << "\nMaximum Absolute Subarray Sum = " << ans;

    return 0;
}
//returns the max absolute subarray sum
//KADANE ALGO
// currSum stores the maximum sum of a CONTIGUOUS subarray ending at current index

// At every element, either:
// 1. Start a new subarray from nums[i]
// 2. Extend previous subarray by adding nums[i]

// If previous subarray sum becomes harmful (negative), starting fresh is better

// maxSum stores the overall maximum subarray sum found so far