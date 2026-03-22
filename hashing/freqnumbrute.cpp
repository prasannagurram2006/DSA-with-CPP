#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 1, 4, 2};
    int n = 7;

    for(int i = 0; i < n; i++) {

        // Check if this element was already counted
        bool alreadyCounted = false;
        for(int k = 0; k < i; k++) {
            if(arr[i] == arr[k]) {
                alreadyCounted = true;
                break;
            }
        }

        if(alreadyCounted)
            continue;
        

        int count = 0;

        // Count frequency
        for(int j = i+1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }

        cout << arr[i] << " -> " << count << endl;
    }

    return 0;
}