//substring with largest variance
//Input: s = "aababbb"
//Output: 3
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    int largestVariance(string s) {

        vector<int> count(26, 0); // stores frequency of each character

        // Count frequency of all characters
        for(char &ch : s) {
            count[ch - 'a']++;
        }

        int result = 0; // stores final maximum variance

        // Try every character as first
        for(char first = 'a'; first <= 'z'; first++) {

            // Try every character as second
            for(char second = 'a'; second <= 'z'; second++) {

                // Skip if either character is absent
                if(count[first - 'a'] == 0 || count[second - 'a'] == 0)
                    continue;

                int firstCount = 0; // count of first character
                int secondCount = 0; // count of second character

                bool pastLowFreq = false; 
                // true if we reset earlier due to negative variance

                // Traverse complete string
                for(char ch : s) {

                    // Increase first character count
                    if(ch == first)
                        firstCount++;

                    // Increase second character count
                    if(ch == second)
                        secondCount++;

                    // Valid substring contains second character
                    if(secondCount > 0) {

                        // Update maximum variance
                        result = max(result, firstCount - secondCount);
                    }
                    else {

                        // Handle case where second char existed before reset
                        if(pastLowFreq) {

                            result = max(result, firstCount - 1);
                        }
                    }

                    // If variance becomes negative
                    if(secondCount > firstCount) {

                        // Reset counts like Kadane's algorithm
                        firstCount = 0;
                        secondCount = 0;

                        // Mark that second char appeared before
                        pastLowFreq = true;
                    }
                }
            }
        }

        return result; // return final answer
    }
};

int main() {

    string s;

    // Take string input from user
    cout << "Enter string: ";
    cin >> s;

    Solution obj;

    // Find largest variance
    int ans = obj.largestVariance(s);

    // Print answer
    cout << "Largest Variance = " << ans << endl;

    return 0;
}