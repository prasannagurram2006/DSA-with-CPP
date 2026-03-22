#include<iostream>
using namespace std;
int main() {
    int n;
    int k;
    int len;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    cout<<"enter n elements";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<"enter k value";
    cin>>k;
    int maxlen=0;
for(int i=0;i<n;i++) {
    int sum=0;
    for(int j=i;j<n;j++) {
        sum+=arr[j];
        if(k==sum) {
            len=j;
            if(maxlen<len) {
                maxlen=len;
            }
        }
    }
}
cout<<"maxlength is"<<maxlen;


    return 0;
}