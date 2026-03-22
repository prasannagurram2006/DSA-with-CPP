#include<iostream>
using namespace std;
void merge(int arr[],int lb,int mid,int ub) {
	 int i=lb;	
	 int j=mid+1;
	 int k=lb;
	int b[100];
	while(i<=mid && j<=ub) {
		if(arr[i]<=arr[j]) {
			b[k]=arr[i];
			i++;
		}
		else {
			b[k]=arr[j];
			j++;
		}
	k++;
	}
		while(i<=mid)
			b[k++]=arr[i++];
		while(j<=ub)
			b[k++]=arr[j++];
		for(int k=lb;k<=ub;k++) 
			arr[k]=b[k];
}
	
void mergesort(int arr[],int lb,int ub) {
	if(lb<ub) {
		int mid=(lb+ub)/2;
		mergesort(arr,lb,mid);
		mergesort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}
int main() {
	int n;
	cout<<"enter no of elements";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	mergesort(arr,0,n-1);
	for(int i=0;i<n;i++) 
		cout<<arr[i]<<" ";
return 0;
}
	
