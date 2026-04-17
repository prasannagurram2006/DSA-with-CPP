#include<iostream>
using namespace std;
#include<deque>
#include<vector>
vector<int> maxsubarr(int arr[],int n,int k) {
    int i=0,j=0;
    deque<int>dq;
    vector<int>ans;
    while(j<n) {
        while(!dq.empty() && arr[dq.back()]<arr[j]) {
            dq.pop_back();
        }                                              
        dq.push_back(j);
        if(j-i+1<k) {
            j++;
        }
        else if(j-i+1==k) {
            ans.push_back(arr[dq.front()]);
            if(dq.front()==i) {
                dq.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}                                                              
int main() {
    int n,k;
    cout<<"enter size of array";
    cin>>n;
    cout<<"enter"<<n<<"elements";
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"enter subarray size";
    cin>>k;
    vector<int> res;
    res=maxsubarr(arr,n,k);
    cout<<"the max element of each subarray of size"<<" "<<k<<"is";
    for(int i=0;i<res.size();i++) {
    cout<<res[i];
    cout<<" ";
    }
}
//while(j < n):
   // remove smaller elements
    //add element

    //if window < k:
        //expand

    //else:
        //take answer
        //remove outgoing
        //slide
        //Side	Use for
//front	👉 Maximum / Answer / Removal when sliding
//back	👉 Cleaning smaller elements / Insertion