#include<iostream>
using namespace std;

int main() {
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    // If lengths differ, cannot be anagrams
    if(s.length() != t.length()) {
        cout << "Not Valid Anagram";
        return 0;
    }

    int freq[26] = {0};

    // Increase frequency using first string
    for(char c : s) {
        freq[c - 'a']++;
    }

    // Decrease frequency using second string
    for(char c : t) {
        freq[c - 'a']--;
    }

    // Check if all frequencies became 0
    for(int i = 0; i < 26; i++) {
        if(freq[i] != 0) {
            cout << "Not Valid Anagram";
            return 0;
        }
    }

    cout << "Valid Anagram";

    return 0;
}