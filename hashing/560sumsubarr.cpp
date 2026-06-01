#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        // stores:
        // prefixSum -> frequency

        mp[0] = 1;
        // Important:
        // handles subarrays starting from index 0

        int prefixSum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {

            // Add current element to prefix sum
            prefixSum += nums[i];

            // We need:
            // prefixSum - previousPrefix = k
            // so:
            // previousPrefix = prefixSum - k

            if(mp.find(prefixSum - k) != mp.end()) {

                // Add frequency of required prefix sum
                count += mp[prefixSum - k];
            }

            // Store current prefix sum
            mp[prefixSum]++;
        }

        return count;
    }
};

int main() {

    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements:\n";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    int ans = obj.subarraySum(nums, k);

    cout << "Number of subarrays = " << ans << endl;

    return 0;
}
// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.
// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2