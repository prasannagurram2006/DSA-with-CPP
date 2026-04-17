#include<iostream>
using namespace std;
#include<map>
int longsubstring(string str) {
    map<char,int> mp;
    int i=0,j=0,mx=0;
    while(j<str.length()) { // If duplicate exists → shrink window
        mp[str[j]]++;
            while(mp[str[j]]>1) {
                mp[str[i]]--;
                if(mp[str[i]]==0) {
                    mp.erase(str[i]);
                }
                i++;
            }
            //now all char are unique
            mx=max(mx,j-i+1);
            j++;

        }
        return mx;
    }
    

int main() {
    cout<<"enter string";
     string str;
     cin>>str;
     int res=longsubstring(str);
     cout<<"The maximum substring of" <<" "<<"unique characters are"<<res;
     return 0;
}