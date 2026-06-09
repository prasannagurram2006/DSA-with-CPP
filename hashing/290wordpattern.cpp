// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Explanation:
// The bijection can be established as:
// 'a' maps to "dog".
// 'b' maps to "cat".
#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string pattern, s;

    // Take pattern input
    cout << "Enter the pattern (example: abba): ";
    cin >> pattern;

    // Clear newline left by cin
    cin.ignore();

    // Take sentence input
    cout << "Enter the string of words (example: dog cat cat dog): ";
    getline(cin, s);

    // Hash map: Pattern character -> Word
    unordered_map<char, string> ptow;

    // Hash map: Word -> Pattern character
    unordered_map<string, char> wtop;

    // Vector to store words from the sentence
    vector<string> words;

    // Convert the input string into individual words
    stringstream ss(s);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    // If number of words and pattern length differ,
    // a valid mapping is impossible
    if (words.size() != pattern.length()) {
        cout << "False" << endl;
        return 0;
    }

    int n = pattern.length();

    // Check each pattern character and corresponding word
    for (int i = 0; i < n; i++) {

        char p = pattern[i];
        string w = words[i];

        // Case 1: Both character and word are new
        if (ptow.find(p) == ptow.end() &&
            wtop.find(w) == wtop.end()) {

            ptow[p] = w;
            wtop[w] = p;
        }

        // Case 2: Both character and word already exist
        else if (ptow.find(p) != ptow.end() &&
                 wtop.find(w) != wtop.end()) {

            // Check if existing mappings match
            if (ptow[p] != w || wtop[w] != p) {
                cout << "False" << endl;
                return 0;
            }
        }

        // Case 3: One exists and the other doesn't
        else {
            cout << "False" << endl;
            return 0;
        }
    }

    cout << "True" << endl;

    return 0;
}
