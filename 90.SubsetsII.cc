// 90. Subsets II
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

#include "define.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>());
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end());
        res.push_back(vector<int>{nums[0]});
        int lastpos = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                lastpos = 0;
            }
            int cursize = res.size();
            for (; lastpos < cursize; ++lastpos) {
                vector<int> tmp = res[lastpos];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
