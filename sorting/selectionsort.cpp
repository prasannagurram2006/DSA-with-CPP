#include<iostream>
using namespace std;
void selectionsort(int arr[],int n) {
	for(int i=0;i<n-1;i++) {
		int minindex=i;
		for(int j=i+1;j<n;j++) {
			if(arr[minindex]>arr[j]){
				minindex=j;
			}
		}
		if(minindex!=i) {
			swap(arr[i],arr[minindex]);
		}
	}
}
int main() {
	int n;
	cout<<"enter no of elements";
	cin>>n;
	int arr[n];
	cout<<"enter elements";
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	selectionsort(arr,n);
	cout<<"sorted array";
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
return 0;
}
			
	



