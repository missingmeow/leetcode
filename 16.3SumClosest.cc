// 16. 3Sum Closest
// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

#include "define.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = INT_MAX - (target > 0 ? target : - target);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int rest = target - nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int tmp = nums[j] + nums[k] - rest;
                if (abs(tmp) < abs(sum - target)) {
                    sum = nums[i] + nums[j] + nums[k];
                }
                if (tmp == 0) {
                    return sum;
                }
                if (tmp > 0) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return sum;
    }
};
