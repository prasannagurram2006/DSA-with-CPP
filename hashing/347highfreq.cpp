// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        // stores:
        // number -> frequency

        // Count frequency of each number
        for(int num : nums) {
            freq[num]++;
        }

        int n = nums.size();

        // Bucket index = frequency
        // Each index stores numbers having that frequency
        vector<vector<int>> bucket(n + 1);//bucket is vector of vectors ,can store multiple nums in a index 

        // Place numbers into corresponding buckets
        for(auto &it : freq) {

            int number = it.first;
            int frequency = it.second;

            bucket[frequency].push_back(number);
        }

        vector<int> ans;

        // Traverse buckets from high frequency index to low
        for(int i = n; i >= 1; i--) {

            // Traverse all numbers in current bucket
            for(int num : bucket[i]) {

                ans.push_back(num);

                // Stop when k elements collected
                if(ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};

int main() {

    int n;

    // Take size input
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    // Take array elements
    cout << "Enter array elements:\n";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;

    // Take k input
    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    // Find top k frequent elements
    vector<int> ans = obj.topKFrequent(nums, k);

    // Print answer
    cout << "Top " << k << " frequent elements are:\n";

    for(int num : ans) {
        cout << num << " ";
    }

    return 0;
}