#include<iostream>
using namespace std;

int countsum(int arr[], int n,int target) {
    
    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int target;
    cout<<"enter target";
    cin>>target;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = countsum(arr, n,target);
    cout << "Number of pairs: " << result;

    return 0;
}
