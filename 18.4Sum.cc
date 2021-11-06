// 18. 4Sum
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

#include "define.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                long long tmp = target - nums[i] - nums[j];
                int m = j + 1, n = nums.size() - 1;
                while (m < n) {
                    long long val = nums[m] + nums[n] - tmp;
                    if (val == 0) {
                        res.push_back({nums[i], nums[j], nums[m], nums[n]});
                        ++m; --n;
                        while (m < n && nums[m] == nums[m - 1]) m++;
                        while (m < n && nums[n] == nums[n + 1]) n--;
                    } else if (val < 0) {
                        ++m;
                        while (m < n && nums[m] == nums[m - 1]) m++;
                    } else {
                        --n;
                        while (m < n && nums[n] == nums[n + 1]) n--;
                    }
                }
            }
        }
        return res;
    }
};