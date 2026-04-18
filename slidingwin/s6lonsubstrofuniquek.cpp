#include<iostream>
using namespace std;
#include<map>
int longsubstring(string str,int k) {
    map<char,int> mp;
    int i=0,j=0,mx=0;
    while(j<str.length()) {
        mp[str[j]]++;//inserting in to map and doing all calc at a time
        if(mp.size()<k) {
            j++;
        }
        else if(mp.size()==k) {
            mx=max(mx,j-i+1);
            j++;
        }
        else if(mp.size()>k) {
            while(mp.size()>k) {
                mp[str[i]]--;
                if(mp[str[i]]==0) {
                    mp.erase(str[i]);
                }
                i++;
            }
            j++;
        }

    }
    return mx;
}
int main() {
    cout<<"enter string";
     string str;
     int k;
     cin>>str;
     cout<<"enter no of unique characters to be there";
     cin>>k;
     int res=longsubstring(str,k);
     cout<<"The maximum substring of "<<k<<" "<<"unique characters are"<<res;
     return 0;
}