//SUBSTRING WITH CONCATENATION OF WORDS
#include <iostream>      
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<int> findSubstring(string s, vector<string>& words) {

        // stores final answer indices
        vector<int> ans;

        // edge case
        if(words.empty() || s.empty())
            return ans;

        // length of one word
        int wordLen = words[0].size();

        // total number of words
        int totalWords = words.size();

        // stores required frequencies of words
        unordered_map<string, int> targetMap;

        // build target frequency map
        for(string word : words) {
            targetMap[word]++;
        }

        // IMPORTANT:
        // we run sliding window for every offset
        // if wordLen = 3
        // offsets = 0,1,2

        for(int offset = 0; offset < wordLen; offset++) {

            // sliding window pointers
            int left = offset;
            int right = offset;

            // stores frequencies inside current window
            unordered_map<string, int> currentMap;

            // counts valid words currently inside window
            int count = 0;

            // move right pointer word-by-word
            while(right + wordLen <= s.size()) {

                // extract current word chunk
                // substr(startIndex, length)
                string word = s.substr(right, wordLen);

                // move right ahead by one word
                right += wordLen;

                // CASE 1:
                // word not present in target map

                if(targetMap.find(word) == targetMap.end()) {

                    // reset everything
                    currentMap.clear();

                    count = 0;

                    // start fresh window
                    left = right;
                }

                // CASE 2:
                // valid word found

                else {

                    // add word to current window
                    currentMap[word]++;

                    count++;

                    // CASE 3:
                    // frequency exceeded

                    // example:
                    // target says foo -> 1
                    // current window has foo -> 2

                    while(currentMap[word] > targetMap[word]) {

                        // remove leftmost word
                        string leftWord = s.substr(left, wordLen);

                        currentMap[leftWord]--;

                        count--;

                        // move left ahead
                        left += wordLen;
                    }

                    // if all words matched
                    if(count == totalWords) {

                        // store starting index
                        ans.push_back(left);

                        // continue searching for next answer

                        // remove leftmost word
                        string leftWord = s.substr(left, wordLen);

                        currentMap[leftWord]--;

                        count--;

                        left += wordLen;
                    }
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s;

    int n;

    // input string
    cout << "Enter the string: ";
    cin >> s;

    // input number of words
    cout << "Enter number of words: ";
    cin >> n;

    vector<string> words(n);

    // input words
    cout << "Enter the words:\n";

    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    // function call
    vector<int> ans = obj.findSubstring(s, words);

    // print answer
    cout << "\nStarting indices are:\n";

    for(int index : ans) {
        cout << index << " ";
    }

    cout << endl;

    return 0;
}
// Start
//   │
//   ▼
// Build target frequency map
//   │
//   ▼
// For every offset (0 → wordLength-1)
//   │
//   ▼
// Initialize window
// (left, right, currentMap, count)
//   │
//   ▼
// Read next word
//   │
//   ▼
// Word exists in target?
//  ┌───────────────┐
//  │      No       │
//  └──────┬────────┘
//         ▼
// Clear map
// count = 0
// left = right
//         │
//         ▼
// Continue

// Word exists?
//       │
//      Yes
//       │
//       ▼
// Add to currentMap

// count++

//       │
//       ▼
// Frequency exceeded?
//       │
//   Yes ▼
// Shrink from left
// until valid

//       │
//       ▼
// count == totalWords ?
//       │
//  ┌────┴────┐
//  │   No    │
//  └────┬────┘
//       ▼
// Continue

//       │
//      Yes
//       ▼
// Store answer

// Remove leftmost word

// Continue