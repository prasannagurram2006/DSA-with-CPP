#include<iostream>
using namespace std; 

void insertsort(int arr[],int n) {
	int j,key;
	for(int i=1;i<n;i++) { 
		key=arr[i]; // initializes key to first arary
		 j=i-1;//j to the previous element to check
		while(j>=0 && arr[j]>key) { 
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}
int main() {
	int n;
	cout<<"enter size of the array";
	cin>>n;
	int arr[n];
	cout<<"enter elements in array";
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	insertsort(arr,n);
	cout<<"sorted array:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
return 0;
}
		
		
			
	