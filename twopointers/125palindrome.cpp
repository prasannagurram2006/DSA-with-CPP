#include <iostream>
#include <string>
#include <cctype>  // for isalnum, tolower

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (char c : s) {
            if (isalnum(c)) {              // ✅ keep only letters and digits
                str += tolower(c);         // ✅ normalize case
            }
            // skip spaces, commas, and other symbols
        }

        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str[left] == str[right]) {
                left++;
                right--;
            } else {
                return false;  // mismatch → not palindrome
            }
        }

        return true;  // no mismatches → palindrome
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);   // ✅ read full line including spaces

    Solution sol;
    if (sol.isPalindrome(input)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}
