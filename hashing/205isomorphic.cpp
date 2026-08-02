// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1:
// Input: s = "egg", t = "add"
// Output: true
#include <iostream>
#include <unordered_map>
using namespace std;

// Function to check whether two strings are isomorphic
bool isomorphic(string s, string t)
{
    // If lengths are different, they cannot be isomorphic
    if (s.length() != t.length())
        return false;

    // Map characters from s -> t
    unordered_map<char, char> stot;

    // Map characters from t -> s
    unordered_map<char, char> ttos;

    for (int i = 0; i < s.length(); i++)
    {
        char c1 = s[i]; // character from s
        char c2 = t[i]; // corresponding character from t

        // Check existing mapping from s to t
        if (stot.count(c1) && stot[c1] != c2)
        {
            return false;
        }

        // Check existing mapping from t to s
        if (ttos.count(c2) && ttos[c2] != c1)
        {
            return false;
        }

        // Store the mapping
        stot[c1] = c2;
        ttos[c2] = c1;
    }

    return true;
}

int main()
{
    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    bool result = isomorphic(s, t);

    if (result)
        cout << "The strings are isomorphic." << endl;
    else
        cout << "The strings are NOT isomorphic." << endl;

    return 0;
}