/*You are given an array of integers nums and an integer k.
Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.
Input: nums = [-1,-2,-3,-4,-5], k = 4
Output: -10*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    long long maxSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        // Prefix sum array
        // prefsum[i] stores sum from index 0 to i
        vector<long long> prefsum(n);

        // First element remains same
        prefsum[0] = nums[0];

        /*
            Building prefix sum array

            Example:
            nums = [2, -1, 3, 4]

            prefsum[0] = 2
            prefsum[1] = 2 + (-1) = 1
            prefsum[2] = 1 + 3 = 4
            prefsum[3] = 4 + 4 = 8
        */

        for(int i = 1; i < n; i++) {

            // current prefix sum =
            // previous prefix sum + current element
            prefsum[i] = prefsum[i - 1] + nums[i];
        }

        // Stores final answer
        long long result = LLONG_MIN;

        /*
            We start from every possible remainder position

            Example:
            k = 3

            start = 0 -> indices: 0,3,6...
            start = 1 -> indices: 1,4,7...
            start = 2 -> indices: 2,5,8...
        */

        for(int start = 0; start < k; start++) {

            int i = start;

            // Kadane style running sum
            long long currsum = 0;

            while(i < n && i + k - 1 < n) {

                // Ending index of current subarray
                int j = i + k - 1;

                /*
                    Finding subarray sum from i to j

                    Formula:

                    sum(i...j) =
                    prefsum[j] - prefsum[i-1]

                    If i == 0:
                    sum = prefsum[j]
                */

                long long subarrsum =
                    prefsum[j] - ((i > 0) ? prefsum[i - 1] : 0);

                /*
                    Kadane logic

                    Either:
                    1. Start new subarray
                    2. Extend previous subarray
                */

                currsum = max(subarrsum, currsum + subarrsum);

                // Update final result
                result = max(result, currsum);

                // Jump by k
                i += k;
            }
        }

        return result;
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

    int k;

    cout << "Enter k value: ";
    cin >> k;

    Solution obj;

    long long ans = obj.maxSubarraySum(nums, k);

    cout << "\nMaximum Subarray Sum = " << ans << endl;

    return 0;
}
 