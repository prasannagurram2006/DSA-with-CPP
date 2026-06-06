#include <iostream>
#include <vector>
#include <algorithm> // for reverse()

using namespace std;

int main() {
    int n;

    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter number of right rotations (k): ";
    cin >> k;

    // If k is greater than array size,
    // reduce it to the effective number of rotations.
    k %= n;

    // Step 1: Reverse the entire array.
    // Example:
    // [1,2,3,4,5,6,7]
    // becomes
    // [7,6,5,4,3,2,1]
    reverse(nums.begin(), nums.end());

    // Step 2: Reverse the first k elements.
    // Example:
    // [7,6,5,4,3,2,1]
    // k = 3
    // [5,6,7,4,3,2,1]
    reverse(nums.begin(), nums.begin() + k);

    // Step 3: Reverse the remaining n-k elements.
    // Example:
    // [5,6,7,4,3,2,1]
    // becomes
    // [5,6,7,1,2,3,4]
    reverse(nums.begin() + k, nums.end());

    cout << "\nArray after rotation: ";
    for(int num : nums) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}