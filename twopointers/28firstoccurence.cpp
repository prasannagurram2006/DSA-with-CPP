// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        // Length of haystack and needle
        int n = haystack.length();
        int m = needle.length();

        // Try every possible starting position in haystack
        // Last valid start index is (n - m)
        for(int i = 0; i <= n - m; i++) {

            // Assume the pattern matches at index i
            bool found = true;

            // Compare each character of needle
            for(int j = 0; j < m; j++) {

                // If any character does not match,
                // this starting position is invalid
                if(haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }

            // If all characters matched,
            // return the starting index
            if(found) {
                return i;
            }
        }

        // Needle was not found anywhere in haystack
        return -1;
    }
};

int main() {

    Solution obj;

    string haystack, needle;

    cout << "Enter the haystack string: ";
    getline(cin, haystack);

    cout << "Enter the needle string: ";
    getline(cin, needle);

    int result = obj.strStr(haystack, needle);

    if(result != -1) {
        cout << "Needle found at index: " << result << endl;
    }
    else {
        cout << "Needle not found in haystack." << endl;
    }

    return 0;
}
//Time complexity=O(n*m)
//space complexity=O(1)