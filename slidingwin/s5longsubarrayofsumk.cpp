#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int longsubarray(vector<int> &arr, int k, int n) {
    int i = 0, j = 0;
    int sum = 0, mx = 0;

    while(j < n) {
        sum += arr[j];   // expand window

        // shrink window until sum <= k
        while(sum > k) {
            sum -= arr[i];
            i++;            //removes not only one element
        }

        // check condition
        if(sum == k) {
            mx = max(mx, j - i + 1);
        }
        if(sum<k) {
        j++;   
        }//move forward
    }

    return mx;
}

int main() {
    cout << "started" << endl;

    int n, k;
    cout << "enter array size" << endl;
    cin >> n;

    vector<int> arr(n);

    cout << "enter array" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "enter sum of longest sub array to check" << endl;
    cin >> k;

    int res = longsubarray(arr, k, n);

    cout << "the longest subarray of sum " << k 
         << " in the array is " << res << endl;

    return 0;
}