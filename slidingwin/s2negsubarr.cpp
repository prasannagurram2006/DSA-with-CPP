#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> firstneg(int arr[],int n,int k) {  //a func which returns vector
    vector<int> ans; 
    queue<int> q;
    int i=0,j=0;
    while(j<n){
        if(arr[j]<0) {
            q.push(arr[j]);//first push the -ve num to queue from starting j value
        }
        if(j-i+1<k) {
            j++; 
        }
        else if(j-i+1==k) { //main calculation*
            if(q.empty()) {
                ans.push_back(0);//if a subarray doesnt have any -ve num then queue will be empty then pushback ans as 0
            }
            else {
                ans.push_back(q.front());//if subarray has a -ve num then pushback to ans from queue
            }
                if(!q.empty() && arr[i] == q.front()) {
                    q.pop();// if the element going out of the window (arr[i]) is the same as the first negative
                            // in queue, remove it because it no longer belongs to the current window
                }
                
                i++;//slide the window
                j++;
            
        }
    }
    return ans;

}
int main() {
    int n,k;
    cout<<"enter array size";
    cin>>n;
    int arr[n];
    cout<<"enter"<<n<<"elements";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<"enter k";//take sub array length
    cin>>k;
    vector<int> result=firstneg(arr,n,k);//call the vector func and store it in result vector
    for(int i=0;i<result.size();i++) {
    cout<<result[i]; 
    }
    
    

}