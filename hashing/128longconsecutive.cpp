#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:

    int longestConsecutive(vector<int>& nums) {

        // Store all numbers in hashset
        // for O(1) lookup
        unordered_set<int> st(nums.begin(), nums.end());

        // Stores final maximum sequence length
        int maxlen = 0;

        // Traverse through unique elements
        for(int num : st) {

            // Check if current number is
            // the starting point of sequence

            // If num-1 does not exist,
            // then sequence starts from num
            if(st.find(num - 1) == st.end()) {

                int curr = num;

                // Current sequence length
                int currlen = 1;

                // Keep checking next consecutive numbers
                while(st.find(curr + 1) != st.end()) {

                    curr++;
                    currlen++;
                }

                // Update maximum length
                maxlen = max(maxlen, currlen);
            }
        }

        return maxlen;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements:\n";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    int ans = obj.longestConsecutive(nums);

    cout << "\nLongest Consecutive Sequence Length = "
         << ans << endl;

    return 0;
}
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.