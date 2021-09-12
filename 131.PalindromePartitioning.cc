// 131. Palindrome Partitioning

// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// A palindrome string is a string that reads the same backward as forward.

#include "define.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        partition(tmp, s, 0, res);
        return res;
    }
private:
    void partition(const vector<string>& part, string& s, int start, vector<vector<string>>& res) {
        for (int i = start; i < s.length(); ++i) {
            int left = start, right = i;
            for (; left < right; ++left, --right) {
                if (s[left] != s[right]) {
                    break;
                }
            }
            if (left >= right) {
                vector<string> tmp = part;
                tmp.push_back(s.substr(start, i - start + 1));
                if (i + 1 == s.length()) {
                    res.push_back(tmp);
                } else {
                    partition(tmp, s, i + 1, res);
                }
            }
        }
    }
};
