#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#include<vector>
int maxarea(vector<int> height,int n) {
    int left=0;
    int right=n-1;
    int maximum=INT_MIN;
    while(left<right) {
        int width=right-left;                           
        int minheight=min(height[left],height[right]);
        maximum=max(width*minheight,maximum);
        if(height[left]==minheight) {
            left++;
        }
        else{
            right--;
        }
    }
    return maximum;
}
int main() {
    int n;
    cout<<"enter the length of heights you enter";
    cin>>n;
    vector<int> height(n);
    cout<<"enter array of heights";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    int res=maxarea(height,n);
    cout<<"the maxarea which can fit max water is"<<res;
    return 0;

}
//the ps is we have to find the max area container that fits the max water in it
//the input is heights i.e arr is [8,1,3] for index 0 is height of container is 8 for 1 its 1 and for 2 its 3
//so we have to find max area how can we find?
//Take two walls from both ends.

// The water stored depends on:
// - how far the walls are
// - the shorter wall

// If one wall is shorter, water will spill from that side.

// So after calculating current water,
// move the shorter wall inward and try to find a taller wall
// that may store more water.

// Keep doing this until both pointers meet,
// while storing the maximum water found.

