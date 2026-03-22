#include<iostream>
using namespace std;
int partition(int arr[],int lb,int ub) {
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end){
    while(start<=ub && pivot>=arr[start]) {
        start++;
    }
    while(pivot<arr[end]) {
        end--;
    }
    if(start<end) {
    swap(arr[start],arr[end]);
    }
}
swap(arr[lb],arr[end]);
return end;
}
void quicksort(int arr[],int lb,int ub) {
    if(lb<ub) {
        int loc=partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
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
	quicksort(arr,0,n-1);
	cout<<"sorted array:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
return 0;
}

    