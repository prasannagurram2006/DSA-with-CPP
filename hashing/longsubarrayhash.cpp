#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
    int n,k;
    cout<<"enter no of elements";
    cin>>n;
    int arr[n];
    cout<<"enter elements"<<n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"enter k value";
    cin>>k;
    int maxlen=0,prefix_sum=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) {
        prefix_sum+=arr[i];
    
    //case 1:check
    if(prefix_sum==k) {
        maxlen=i+1;
    }
    //case2:if prefix_sum-k exists
    if(mp.find(prefix_sum-k)!=mp.end()) {
        int len=i-mp[prefix_sum-k];
        if(maxlen<len) {
            maxlen=len;
        }
    }
    //case3:if wont exists
    if(mp.find(prefix_sum)==mp.end()) {
        mp[prefix_sum]=i;
    }
}
cout<<"the longest subarray is of length"<<maxlen;
return 0;



}