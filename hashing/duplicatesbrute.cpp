#include<iostream>
using namespace std;

int duplicates(int arr[], int n) {
    int count=0;
    
    

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                
                count++;
            
            
            }
            
            
        }
    }
    cout<<count;

    
    
    
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = duplicates(arr, n);
    

    return 0;
}