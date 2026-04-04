#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 5, 7, -1, 5};
    int n = 5;                                          //Take current number arr[i]

        
                                                        //👉 "What number do I need to make target?"

                                                //Check if that number already appeared before.

                                                //If yes → we found valid pair(s).
    int target = 6;                                 //arr[i] + x = target
                                                    //x = target - arr[i]

    unordered_map<int, int> freq;
    int count = 0;

    for(int i = 0; i < n; i++) {
        int x = target - arr[i];

        if(freq.find(x) != freq.end()) {
            count += freq[x];
        }

        freq[arr[i]]++;
    }

    cout << count;
}