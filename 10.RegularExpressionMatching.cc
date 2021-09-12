// 10. Regular Expression Matching
// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

#include "define.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> match(p.size() + 1, vector<bool>(s.size() + 1, false));
        match[0][0] = true;
        int i = 1;
        while (i < p.size() && p[i] == '*') {
            match[i][0] = match[i + 1][0] = true;
            i += 2;
        }
        for (i = 0; i < p.size(); ++i) {
            // 下一个字符是 *
            bool bstar = i + 1 < p.size() && p[i + 1] == '*';
            for (int j = 0; j < s.size(); ++j) {
                if (bstar) {
                    if (match[i][j + 1]) {
                        match[i + 1][j + 1] = match[i + 2][j + 1] = true;
                    } else if ((p[i] == s[j] || p[i] == '.')) {
                        match[i + 1][j + 1] = match[i + 2][j + 1] = match[i][j] || match[i + 1][j] || match[i][j + 1];
                    }
                } else if (p[i] == '.' || p[i] == s[j]) {
                    match[i + 1][j + 1] = match[i][j];
                }
            }
            if (bstar) {
                ++i;
            }
        }
        return match[p.size()][s.size()];
    }
};


class Solution1 {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        bool bfirstMatch = !s.empty() && (p[0] == s[0] || p[0] == '.');
        if (p.size() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (bfirstMatch && isMatch(s.substr(1), p));
        } else {
            return bfirstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main(int argc, char** argv) {
    Solution1 s;
    cout << s.isMatch("acaabbaccbbacaabbbb", "a*.*b*.*a*aa*a*") << endl;
    // cout << s.isMatch("", "a*.*") << s.isMatch("", "") << s.isMatch("", ".*a");
    return 0;
}