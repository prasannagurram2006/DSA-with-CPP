#include<iostream>
using namespace std;
void bubblesort(int arr[],int n) {
	for(int i=0;i<n-1;i++) {
		for(int j=0;j<n-i-1;j++) {
			if(arr[j]>arr[j+1]) {
				swap(arr[j],arr[j+1]);
			}
		}
	}
}
int main() {
	int n;
	cout<<"enter no of elements";
	cin>>n;
	int arr[n];
	cout<<"enter n elements";	
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	bubblesort(arr,n);
	cout<<"sorted array:";
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
return 0;
}
		


