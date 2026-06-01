#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubarraySum(vector<int>& nums) {

    int currSum = nums[0];
    int maxSum = nums[0];

    for(int i = 1; i < nums.size(); i++) {

        // Either start new subarray
        // or continue previous one
        currSum = max(nums[i], currSum + nums[i]);

        // Update answer
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main() {

    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = maxSubarraySum(nums);

    cout << "Maximum subarray sum = " << ans;

    return 0;
}
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.