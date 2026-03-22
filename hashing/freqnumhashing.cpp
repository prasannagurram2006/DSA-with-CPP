#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
    int n;
    cout<<"enter n value";
    cin>>n;
    int arr[n];
    cout<<"enter n elements";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++) {
        freq[arr[i]]++;
    }
    for(auto it:freq) {
        cout<<it.first<<"->"<<it.second<<endl;
    }
    return 0;
}