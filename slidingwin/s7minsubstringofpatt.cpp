#include <bits/stdc++.h>
using namespace std;
#include <map>

string minwindow(string str, string pattern) {
    map<char,int> mp;

    // fill map
    for(char c:pattern) {
        mp[c]++;
    }

    int count = mp.size(); // ✅ after map filling

    int i=0, j=0;
    int minlen = INT_MAX;
    int start=0;

    while(j < str.length()) {

        if(mp.find(str[j]) != mp.end()) {
            mp[str[j]]--;
            if(mp[str[j]] == 0) {
                count--;
            }
        }

        if(count == 0) {
            while(count == 0) {

                // ✅ update before breaking
                if(j - i + 1 < minlen) {
                    minlen = j - i + 1;
                    start = i;
                }

                if(mp.find(str[i]) != mp.end()) {
                    mp[str[i]]++;
                    if(mp[str[i]] > 0) {
                        count++;
                    }
                }
                i++;
            }
        }
        j++;
    }

    if(minlen == INT_MAX) {
        return "";
    }

    return str.substr(start, minlen); // ✅ fixed
}

int main() {
    string str;
    cout << "enter string: ";
    cin >> str;

    string pattern;
    cout << "enter pattern: ";
    cin >> pattern;

    string res = minwindow(str, pattern);

    if(res == "") {
        cout << "No valid substring found that contains all characters of t" << endl;
    } else {
        cout << "Smallest substring in s that contains all characters of t: "
             << res << endl;
    }

    return 0;
}