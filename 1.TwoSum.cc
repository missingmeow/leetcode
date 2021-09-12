// 1. Two Sum
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

#include "define.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> val;
        for (int i = 0; i < nums.size(); i++) {
            if (val.find(nums[i]) != val.end()) {
                res.push_back(val[nums[i]]);
                res.push_back(i);
                return res;
            }
            val[target - nums[i]] = i;
        }
        return res;
    }
};


int main() {
    vector<int> val;
    val.push_back(1);
    val.push_back(2);
    val.push_back(3);
    val.push_back(4);
    Solution s;
    vector<int> res = s.twoSum(val, 6);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << std::endl;
    return 0;
}
