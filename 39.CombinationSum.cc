// 39. Combination Sum
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

#include "define.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        recursion(res, cur, target, candidates, 0);
        return res;
    }
private:
    void recursion(vector<vector<int>>& res, vector<int> cur, int target, vector<int>& candidates, int left) {
        for (int i = left; i < candidates.size(); ++i) {
            int temp = target - candidates[i];
            if (temp < 0) {
                break;
            }
            cur.push_back(candidates[i]);
            if (temp == 0) {
                res.push_back(cur);
                break;
            }
            recursion(res, cur, temp, candidates, i);
            cur.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> temp{2,7,6,3,5,1};
    auto res = s.combinationSum(temp, 9);
    for (auto& i : res) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}