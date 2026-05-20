#include <iostream>
#include <vector>
#include <cmath>   // for abs
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> squares(n);
        int left = 0;
        int right = n - 1;
        int pos = n - 1;

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                squares[pos] = nums[left] * nums[left];
                left++;
            } else {
                squares[pos] = nums[right] * nums[right];
                right--;
            }
            pos--;
        }
        return squares;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " sorted numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> ans = sol.sortedSquares(nums);

    cout << "Sorted squares: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
