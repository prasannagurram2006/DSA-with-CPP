#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    /*
    INTUITION:

    Since array contains only 0, 1, 2:

    - keep 0s on left
    - keep 2s on right
    - 1s automatically stay in middle

    Use 3 pointers:

    low  -> position for next 0
    mid  -> current element checking
    high -> position for next 2

    If nums[mid] == 0:
    swap with low and move both

    If nums[mid] == 1:
    just move mid

    If nums[mid] == 2:
    swap with high and move high only

    Don't move mid after swapping with high
    because swapped element is still unchecked.
    */

    void sortColors(vector<int>& nums) {

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high) {

            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if(nums[mid] == 1) {
                mid++;
            }

            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {

    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    obj.sortColors(nums);

    cout << "Sorted array: ";

    for(int x : nums) {
        cout << x << " ";
    }

    return 0;
}