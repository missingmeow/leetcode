// 40. Combination Sum II
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

#include "define.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        recursion(res, cur, target, candidates, 0);
        return res;
    }
private:
    void recursion(vector<vector<int>>& res, vector<int> cur, int target, vector<int>& candidates, int left) {
        for (int i = left; i < candidates.size(); ++i) {
            if (i > left && candidates[i] == candidates[i - 1]) {
                continue;
            }
            int temp = target - candidates[i];
            if (temp < 0) {
                break;
            }
            cur.push_back(candidates[i]);
            if (temp == 0) {
                res.push_back(cur);
                break;
            }
            recursion(res, cur, temp, candidates, i + 1);
            cur.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> temp{10,1,2,7,6,1,5};
    auto res = s.combinationSum2(temp, 8);
    for (auto& i : res) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}