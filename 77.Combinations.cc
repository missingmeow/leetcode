// 77. Combinations
// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

// You may return the answer in any order.

#include "define.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        recursion(res, cur, n, 1, k);
        return res;
    }

private:
    void recursion(vector<vector<int>>& res, vector<int> cur, int n, int left, int k) {
        if (k == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = left; i <= n; ++i) {
            cur.push_back(i);
            recursion(res, cur, n, i + 1, k - 1);
            cur.pop_back();
        }
    }
};