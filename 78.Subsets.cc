// 78. Subsets
// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 #include "define.h"

 class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>());
        for (int i = 0; i < nums.size(); ++i) {
            int cursize = res.size();
            for (int j = 0; j < cursize; ++j) {
                vector<int> tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
