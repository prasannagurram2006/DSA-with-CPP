#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;  // use size() for vector
        while (left < right) {
            swap(s[left], s[right]); // swap characters
            left++;
            right--;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> s(n);
    cout << "Enter characters one by one:\n";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    Solution sol;
    sol.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}
