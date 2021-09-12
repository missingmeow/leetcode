// 5. Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.

#include "define.h"

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }
        int longest = 1, start = 0;
        for (int i = 1; i < s.size() - longest / 2; i++) {
            int curMax = max(curPalindrome(s, i - 1, i, 0), curPalindrome(s, i - 1, i + 1, 1));
            if (curMax > longest) {
                longest = curMax;
                start = i - curMax / 2;
            }
        }
        return s.substr(start, longest);
    }
private:
    int curPalindrome(const string& s, int left, int right, int curMax) {
        while (true) {
            if (left < 0 || right >= s.size()) {
                break;
            }
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
            curMax += 2;
        }
        return curMax;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    cout << s.longestPalindrome("babad") << endl;
    cout << s.longestPalindrome("cbbd") << endl;
    cout << s.longestPalindrome("ac") << endl;
    return 0;
}
