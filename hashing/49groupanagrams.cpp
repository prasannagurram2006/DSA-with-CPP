#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // HashMap:
        // key   -> sorted string
        // value -> all anagrams having same sorted string
        unordered_map<string, vector<string>> mp;

        // Traverse all words
        for(string word : strs) {

            // Copy original word
            string temp = word;

            // Sort copied word
            sort(temp.begin(), temp.end());

            // Store original word using sorted word as key
            mp[temp].push_back(word);
        }

        // Final answer
        vector<vector<string>> ans;

        // Put all hashmap values into answer vector
        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter strings:\n";

    for(int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution obj;

    vector<vector<string>> result = obj.groupAnagrams(strs);

    cout << "\nGrouped Anagrams:\n";

    // Print grouped anagrams
    for(auto group : result) {

        cout << "[ ";

        for(string word : group) {
            cout << word << " ";
        }

        cout << "]\n";
    }

    return 0;
}