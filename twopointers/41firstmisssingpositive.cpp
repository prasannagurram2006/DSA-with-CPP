#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    /*
    INTUITION:

    We only care about positive numbers from 1 to n.

    Why?
    Because for an array of size n,
    the smallest missing positive will always lie in range [1, n+1].

    Example:
    n = 5

    If array contains:
    1 2 3 4 5
    then answer = 6

    Otherwise one number from 1..5 is missing.

    --------------------------------------------------

    MAIN IDEA:

    Put every number in its correct position.

    Correct position rule:

    value x should be at index x-1

    Example:
    1 -> index 0
    2 -> index 1
    3 -> index 2

    --------------------------------------------------

    We ignore:
    - negative numbers
    - 0
    - numbers > n

    because they are useless for finding smallest missing positive.

    --------------------------------------------------

    After placing numbers correctly:

    Scan array:
    if nums[i] != i+1
    then i+1 is missing.

    Example:
    [1,-1,3,4]

    index 0 should contain 1 -> correct
    index 1 should contain 2 -> missing

    answer = 2
    */

    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        // STEP 1:
        // Place every valid number at its correct index
        for(int i = 0; i < n; i++) {

            /*
            Keep swapping until:
            - number becomes invalid
            - OR already reaches correct position
            - OR duplicate blocks swapping
            */
            while(nums[i] > 0 &&
                  nums[i] <= n &&
                  nums[i] != nums[nums[i] - 1]) {

                // place current number at correct index
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // STEP 2:
        // Find first missing positive
        for(int i = 0; i < n; i++) {

            // correct value at index i should be i+1
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }

        // STEP 3:
        // all numbers from 1 to n are present
        return n + 1;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    int ans = obj.firstMissingPositive(nums);

    cout << "Smallest missing positive number is: " << ans;

    return 0;
}