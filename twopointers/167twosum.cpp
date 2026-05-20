#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> res;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                res.push_back(left + 1);   // ✅ 1-based index
                res.push_back(right + 1);
                return res;
            } else if (sum < target) {
                left++;   // need bigger sum
            } else {
                right--;  // need smaller sum
            }
        }
        return res;  // empty if no solution
    }
};

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter " << n << " sorted numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    Solution sol;
    vector<int> ans = sol.twoSum(numbers, target);

    if (!ans.empty()) {
        cout << "Indices (1-based): " << ans[0] << ", " << ans[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}
