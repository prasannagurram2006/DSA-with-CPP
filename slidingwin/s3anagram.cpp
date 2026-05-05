#include<iostream>  // FIXED SIZE SLIDING WINDOW PROBLEM
#include<map>
using namespace std;
int anagram(string str,string pattern) {
   map<char,int> mp; 
   for(char c:pattern) {
    mp[c]++;            //stores the freq of pattern in map
   }
   int count=mp.size();
   int i=0,j=0;
   int ans=0;
   while(j<str.size()) {
        if(mp.find(str[j])!=mp.end()) {//means if j has a char which is in map i.e pattern
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

    // While removing the left character from the sliding window,
// increment its frequency back in the map.
//
// If frequency becomes 1, it means:
// earlier this character was perfectly matched (freq was 0)
// but now one occurrence is missing from the window.
//
// So this character becomes unmatched again,
// therefore increase count.
//
// We check ==1 and NOT >0 because count should increase
// only once when the character changes from matched -> unmatched.