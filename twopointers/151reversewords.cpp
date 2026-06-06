#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        // Step 1: Remove leading, trailing, and extra spaces
        string clear = "";
        bool prevSpace = true;

        for(char ch : s)
        {
            if(ch == ' ')
            {
                // Add only one space between words
                if(!prevSpace)
                {
                    clear += ' ';
                    prevSpace = true;
                }
            }
            else
            {
                clear += ch;
                prevSpace = false;
            }
        }

        // Remove trailing space if present
        if(!clear.empty() && clear.back() == ' ')
        {
            clear.pop_back();
        }

        int n = clear.length();

        // Step 2: Reverse the entire string
        reverse(clear.begin(), clear.end());

        // Step 3: Reverse each word
        int start = 0;

        while(start < n)
        {
            int end = start;

            // Find the end of the current word
            while(end < n && clear[end] != ' ')
            {
                end++;
            }

            // Reverse the current word
            reverse(clear.begin() + start, clear.begin() + end);

            // Move to the next word
            start = end + 1;
        }

        return clear;
    }
};

int main()
{
    Solution obj;
    string s;

    cout << "Enter a sentence (can contain multiple spaces): ";
    getline(cin, s);

    string result = obj.reverseWords(s);

    cout << "Reversed words sentence: " << result << endl;

    return 0;
}