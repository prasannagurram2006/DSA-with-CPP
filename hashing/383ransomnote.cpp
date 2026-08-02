#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> mp;

    // Store frequency of characters in magazine
    for (int i = 0; i < magazine.length(); i++) {
        mp[magazine[i]]++;
    }

    // Check if each character of ransomNote is available
    for (int i = 0; i < ransomNote.length(); i++) {
        char c = ransomNote[i];

        // Character exists and at least one copy is available
        if (mp.find(c) != mp.end() && mp[c] > 0) {
            mp[c]--;
        }
        // Character not found OR no copies left
        else if (mp.find(c) == mp.end() || mp[c] == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string ransomNote, magazine;

    cout << "Enter ransom note: ";
    cin >> ransomNote;

    cout << "Enter magazine string: ";
    cin >> magazine;

    if (canConstruct(ransomNote, magazine)) {
        cout << "True - Ransom note can be constructed." << endl;
    } else {
        cout << "False - Ransom note cannot be constructed." << endl;
    }

    return 0;
}