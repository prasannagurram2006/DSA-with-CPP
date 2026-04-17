#include<iostream>
#include<map>
using namespace std;
int anagram(string str,string pattern) {
   map<char,int> mp; 
   for(char c:pattern) {
    mp[c]++;
   }
   int count=mp.size();
   int i=0,j=0;
   int ans=0;
   while(j<str.size()) {
        if(mp.find(str[j])!=mp.end()) {
            mp[str[j]]--;
            if(mp[str[j]]==0) {
            count--;
            }
        }
        if(j-i+1<pattern.length()) {
            j++;
        }
        else if(j-i+1==pattern.length()) {
            if(count==0) {
                ans++;
            }
            if(mp.find(str[i])!=mp.end()) {
                mp[str[i]]++;
                if(mp[str[i]]==1) {
                    count++;
                }
            }
            i++;
            j++;
        }
        
   }
   return ans;
}
int main() {
    string str;
    cout<<"enter string";
    cin>>str;
    string pattern;
    cout<<"enter pattern";
    cin>>pattern;
    int res=anagram(str,pattern);
    cout<<"result is"<<res;
    return 0;
}

    