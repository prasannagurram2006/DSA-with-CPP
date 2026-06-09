// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    
    int n;

    // Input size of array
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;

    // Input value of k
    cout << "Enter value of k: ";
    cin >> k;

    // Hash map to store:
    // Key   -> array element
    // Value -> latest index where element appeared
    unordered_map<int, int> mp;

    bool found = false;

    // Traverse the array
    for(int i = 0; i < nums.size(); i++) {

        // Check if current element already exists in map
        if(mp.find(nums[i]) != mp.end()) {

            // Calculate distance between current index
            // and previous occurrence index
            if(i - mp[nums[i]] <= k) {
                found = true;
                break;
            }
        }

        // Store/update the latest index of current element
        mp[nums[i]] = i;
    }

    // Display result
    if(found) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}