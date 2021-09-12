// 44. Wildcard Matching
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

#include "define.h"

/* // 递归算法，不通过，且目前这个写得还不够优雅
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p == s) return true;
        if (p.empty()) return false;
        bool isWildcard = false;
        int cur = 0, i = 0;
        for (; i < p.size();) {
            if (p[i] == '*') {
                isWildcard = true;
                i++;
            } else if (cur == s.size()) {
                break;
            } else if (p[i] == '?') {
                if (isWildcard) {
                    if (isMatch(s.substr(cur + 1), p.substr(i + 1))) {
                        return true;
                    }
                    cur++;
                } else {
                    cur++; i++;
                }
            } else if (p[i] != s[cur]) {
                if (isWildcard) {
                    cur++;
                } else {
                    return false;
                }
            } else if (p[i] == s[cur]) {
                if (isWildcard) {
                    if (isMatch(s.substr(cur + 1), p.substr(i + 1))) {
                        return true;
                    }
                    cur++;
                } else {
                    cur++; i++;
                }
            }
        }
        if (i == p.size() && cur == s.size()) {
            return true;
        }
        bool bAll = i - 1 < p.size();
        for (i = i - 1; i < p.size(); i++) {
            if (p[i] != '*') {
                bAll = false;
            }
        }
        if (bAll) return true;
        return false;
    }
};
*/

// 动态规划算法试下
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> arr(n + 1, vector<bool>(m + 1, false));
        arr[0][0] = true; // 字符串都为空时还是能通过的
        int i = 1;
        while (i <= n && p[i - 1] == '*') {
            arr[i++][0] = true;
        }
        for (i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == '*') {
                    arr[i][j] = arr[i - 1][j - 1] || arr[i - 1][j] || arr[i][j - 1];
                } else if (p[i - 1] == '?' && arr[i - 1][j - 1]) {
                    arr[i][j] = true;
                } else if (p[i - 1] == s[j - 1] && arr[i - 1][j - 1]) {
                    arr[i][j] = true;
                }
            }
        }
        return arr[n][m];
    }
};

// 直接循环标记上次星号的位置
class Solution1 {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, iMark = -1, jMark = -1, m = s.length(), n = p.length();
        while (i < m) {
            if (j < n && (p[j] == '?' || p[j] == s[i])) {
                i++; j++;
            } else if (j < n && p[j] == '*') {
                iMark = i;
                jMark = j++;
            } else if (iMark >= 0) {
                i = ++iMark;
                j = jMark + 1;
            } else {
                return false;
            }
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};

int main(int argc, const char** argv) {
    Solution1 s;
    // cout << s.isMatch("aa", "*?") << endl;
    cout << s.isMatch("adceb", "*a*b") << endl;
    cout << s.isMatch("acdcb", "a*c?b") << endl;
    cout << s.isMatch("", "a*") << endl;
    cout << s.isMatch("zacabz", "*a?b*") << endl;
    // assert(s.isMatch("aecaatfb", "*a?b") == false);
    return 0;
}