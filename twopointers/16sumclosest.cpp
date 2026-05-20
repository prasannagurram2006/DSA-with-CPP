#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {

        // Sort array for two pointer approach
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Initialize with first triplet sum
        int bestsum = nums[0] + nums[1] + nums[2];

        // Fix one element
        for(int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            // Find closest pair with nums[i]
            while(left < right) {

                int currentsum = nums[i] + nums[left] + nums[right];

                // Update closest sum
                if(abs(target - currentsum) < abs(target - bestsum)) {
                    bestsum = currentsum;
                }

                // Exact target found
                if(currentsum == target) {
                    return currentsum;
                }

                // Need bigger sum
                else if(currentsum < target) {
                    left++;
                }

                // Need smaller sum
                else {
                    right--;
                }
            }
        }

        return bestsum;
    }
};

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    int ans = obj.threeSumClosest(nums, target);

    cout << "Closest sum is: " << ans;

    return 0;
}