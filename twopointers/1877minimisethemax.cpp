#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:

    int minPairSum(vector<int>& nums) {

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Two pointers
        int left = 0;
        int right = nums.size() - 1;

        // Store maximum pair sum
        int maxsum = INT_MIN;

        // Step 2: Pair smallest with largest
        while (left < right) {

            // Current pair sum
            int sum = nums[left] + nums[right];

            // Update maximum pair sum
            maxsum = max(maxsum, sum);

            // Move pointers
            left++;
            right--;
        }

        // Final minimized maximum pair sum
        return maxsum;
    }
};

int main() {

    int n;

    cout << "Enter even number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    int result = obj.minPairSum(nums);

    cout << "Minimized Maximum Pair Sum = " << result;

    return 0;
}