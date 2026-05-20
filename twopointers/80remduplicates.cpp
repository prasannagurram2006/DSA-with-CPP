#include <iostream>
#include <vector>
using namespace std;

// Intuition:
/*Since the array is sorted, duplicates always appear together.

 We do not actually remove elements from the array.
 Instead, we build the valid array at the front of the same array.
Use two pointers:
 i -> position where next valid element should be placed ,overwrites
 j -> traverses the array,reads the array

 First two elements are always valid because each element
 can appear at most twice.

 For every next element, check nums[i-2]:
 - if nums[j] == nums[i-2], then two same elements already
  exist in valid portion, so current element would become
   the 3rd duplicate -> skip it
 - otherwise current element is valid, so place it at nums[i]

This works because the array is sorted, so duplicates stay adjacent.*/

int removeDuplicates(vector<int>& nums) {

    if(nums.size() <= 2)
        return nums.size();

    int i = 2;

    for(int j = 2; j < nums.size(); j++) {

        if(nums[j] != nums[i - 2]) {

            nums[i] = nums[j];
            i++;
        }
    }

    return i;
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k = removeDuplicates(nums);

    cout << "Length after removing duplicates: " << k << endl;

    cout << "Modified array: ";

    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}