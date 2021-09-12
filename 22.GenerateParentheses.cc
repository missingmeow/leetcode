// 22. Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include "define.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        reverse(n, n, "", res);
        return res;
    }
    void reverse(int left, int right, string cur, vector<string>& res) {
        if (left == right) {
            reverse(left - 1, right, cur + '(', res);
        } else if (left == 0) {
            cur += string(right, ')');
            res.push_back(cur);
        } else {
            if (left > 0) {
                reverse(left - 1, right, cur + '(', res);
            }
            if (right > left) {
                reverse(left, right - 1, cur + ')', res);
            }
        }
    }
};

