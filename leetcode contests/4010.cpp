#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>// for gcd and max
using namespace std;

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long gcdnum = __gcd(nums[i], nums[j]);
                ans = max(ans, (1LL * nums[i] * nums[j]) / (gcdnum * gcdnum));
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long result = obj.maxPairStrength(nums);

    cout << "Maximum Pair Strength = " << result << endl;

    return 0;
}
// You are given an integer array nums.

// Choose exactly one pair of distinct indices i and j. The strength of the pair is defined as (nums[i] * nums[j]) / gcd(nums[i], nums[j])2.

// Return the maximum strength over all possible pairs.

 

// Example 1:

// Input: nums = [2,3,5]

// Output: 15

// Explanation:

// Choosing i = 1 and j = 2 gives strength (3 * 5) / gcd(3, 5)2 = 15 / 1 = 15, which is the maximum over all pairs.
//****gcd using euclidian algo
// long long findGCD(long long a, long long b) {
//     while (b != 0) {
//         long long temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }
//a,b=>b,a%b;