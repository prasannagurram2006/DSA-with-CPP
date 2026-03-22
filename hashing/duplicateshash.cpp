#include<iostream>
using namespace std;
#include<unordered_set>

int main() {
unordered_set<int> s; //set is not an array
int current;

    int n;
    cout<<"enter n value";
    cin>>n;
    int arr[n];
    cout<<"enter n elements";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
for(int i=0;i<n;i++) {
    current=arr[i];             //if(s.find(current) != s.end()) you can use this too but used one is better
        if(s.count(current)){ //if current is  equal to end no duplicates 
            cout<<"duplicates are present";//If count is 1 → true → element exists

                                            //If count is 0 → false → element not present
            break;
        }
        else {
            s.insert(current);
        }
    }
    

}
