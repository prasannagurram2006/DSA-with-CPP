#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int i = 0;

        for (int j = 0; j < t.size() && i < s.size(); j++) {

            if (s[i] == t[j]) {
                i++;
            }
        }

        return i == s.size();
    }
};

int main() {

    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    Solution obj;

    if (obj.isSubsequence(s, t)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}