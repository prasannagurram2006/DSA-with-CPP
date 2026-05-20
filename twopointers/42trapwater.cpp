#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int trap(vector<int>& height,int n) {
        int left=0;
        int right=n-1;
        int leftmax=0;
        int rightmax=0;
        int water=0;
        while(left<right) {
            leftmax=max(leftmax,height[left]);
            rightmax=max(rightmax,height[right]);
            if(leftmax<=rightmax) {
                water+=leftmax-height[left];
                left++;
            }
            else  {
                water+=rightmax-height[right];
                right--;
            }
        }
        return water;
    }
};
int main() {
    int n;
    cout<<"enter number of heights";
    cin>>n;
    vector<int> height(n);
    cout<<"enter array of heights";
    for(int i=0;i<n;i++) {
        cin>>height[i];
    }
     Solution obj;
     int ans=obj.trap(height,n);
     cout<<"the amount of water which can trap the water is"<<ans;
     return 0;
    }