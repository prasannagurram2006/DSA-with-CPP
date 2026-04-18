#include <iostream>
#include <vector>
using namespace std;

int characterReplacement(string s, int k) {
    vector<int> freq(26, 0);
    
    int i = 0, j = 0;
    int maxFreq = 0;
    int maxLen = 0;

    while (j < s.length()) {
        freq[s[j] - 'A']++;
        maxFreq = max(maxFreq, freq[s[j] - 'A']);

        while ((j - i + 1) - maxFreq > k) {
            freq[s[i] - 'A']--;
            i++;
        }

        maxLen = max(maxLen, j - i + 1);
        j++;
    }

    return maxLen;
}

int main() {
    string s;
    int k;

    cout << "Enter string (uppercase): ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    int result = characterReplacement(s, k);
    cout << "Answer: " << result << endl;

    return 0;
}