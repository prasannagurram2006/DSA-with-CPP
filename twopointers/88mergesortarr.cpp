// Example 1:
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
#include<iostream>
using namespace std;
#include<vector>
vector<int> mergesorted (vector<int> nums1,vector<int> nums2,int m,int n) {
    int i=m-1;//it points to the last or highest num in nums1
    int j=n-1;//it points to the last or highest num in nums2
    int size=nums1.size();
    while(i>=0 && j>=0) {
        if(nums1[i]>nums2[j]) {
            nums1[size-1]=nums1[i];
            i--;
            size--;
        }
        else if(nums1[i]<=nums2[j]) {
            nums1[size-1]=nums2[j];
            j--;
            size--;
        }
    }
    //if j=-1 that means every index element is checked and i>0  means you have something but i i.e nums[i]doesnt need to check cause it is already sorted 
    //if j>=0 and i=-1 thats a red sign cause there are elements still need to check in nums2 ,just copy them
    //so for that this is the case
    while(j>=0) {
        nums1[size-1]=nums2[j];
        j--;
        size--;
    }
    return nums1;
    }
    int main() {

    int m, n;

    cout << "Enter number of valid elements in nums1 (m): ";
    cin >> m;

    cout << "Enter number of elements in nums2 (n): ";
    cin >> n;

    vector<int> nums1(m + n);
    vector<int> nums2(n);

    cout << "\nEnter " << m
         << " sorted elements for nums1 (DO NOT enter the trailing zeros):\n";

    for(int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    // Remaining n positions stay as 0
    for(int i = m; i < m + n; i++) {
        nums1[i] = 0;
    }

    cout << "\nEnter " << n
         << " sorted elements for nums2:\n";

    for(int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    vector<int> result = mergesorted(nums1, nums2, m, n);

    cout << "\nMerged Array:\n";

    for(int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}