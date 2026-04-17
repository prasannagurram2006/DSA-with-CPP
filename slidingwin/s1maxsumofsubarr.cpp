#include<iostream>
using namespace std;
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
    int i=0,j=0,sum=0,mx=0;
    while(j<n) { //end case do the computation until j<n
        sum=sum+arr[j];//calculate its sum
        if(j-i+1<k) {
            j++;// if suppose subarray len is less than k then increase j value such that subarray will increse
        }
        else if (j-i+1==k) {
          mx=max(mx,sum);//if it is equal to subarray then find max subarray
           
          sum=sum-arr[i]; //to calculate next next subarray sum of size then remove starting i sum
          i++;
          j++;//increase i and j to calculate next subarray
        }
    }
    cout<<"the maximum sub array of size"<<k<<"is equal to"<<mx;
    return 0;
    

}