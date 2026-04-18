#include<iostream>
#include<map>
using namespace std;

int main() {
    string s;
    cout << "enter string";
    cin >> s;

    map<char,int> mp;
    int maxlen = 0;
    int i = 0;

    for(int j = 0; j < s.length(); j++) {
        mp[s[j]]++;

        while(mp[s[j]] > 1) {
            mp[s[i]]--;
            i++;
        }

        maxlen = max(maxlen, j - i + 1);
    }

    cout << maxlen;
    return 0;
}