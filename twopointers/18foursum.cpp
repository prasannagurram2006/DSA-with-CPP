#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    vector<vector<int>> foursum(vector<int>& nums, int target, int n) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> quad;

        for(int i = 0; i < n - 3; i++) {

            // Skip duplicate i
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for(int j = i + 1; j < n - 2; j++) {

                // Skip duplicate j
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;

                while(left < right) {

                    long long sum =
                        (long long)nums[i] +
                        nums[j] +
                        nums[left] +
                        nums[right];

                    if(sum == target) {

                        quad.push_back(
                            {nums[i], nums[j], nums[left], nums[right]}
                        );

                        left++;
                        right--;

                        // Skip duplicate left
                        while(left < right &&
                              nums[left] == nums[left - 1]) {
                            left++;
                        }

                        // Skip duplicate right
                        while(left < right &&
                              nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }

                    else if(sum > target) {
                        right--;
                    }

                    else {
                        left++;
                    }
                }
            }
        }

        return quad;
    }
};

int main() {

    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    // Correct function call
    vector<vector<int>> ans =
        obj.foursum(nums, target, n);

    cout << "Quadruplets are:\n";

    for(int i = 0; i < ans.size(); i++) {

        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}