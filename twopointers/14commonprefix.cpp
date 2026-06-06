#include<iostream>
using namespace std;
#include<vector>
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
// Example 1:
// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl" 
string longprefix(vector<string>strs) {
    string prefix="";
    for(int pos=0;pos<strs[0].size();pos++) {
        char currentchar=strs[0][pos];
        for(int word=0;word<strs.size();word++) {
            if(pos>strs[word].size() || currentchar!=strs[word][pos]) {
                return prefix;
            }

        }
        prefix+=currentchar;
    }
    return prefix;
}
int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();  // clear newline left in buffer

    vector<string> strs(n);  // vector with n slots

    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        getline(cin, strs[i]);  // allows spaces in input
    }
    string result=longprefix(strs);
    cout<<"the longest common prefix is"<<result;
    return 0;

}
