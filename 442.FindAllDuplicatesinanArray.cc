// 442. Find All Duplicates in an Array
// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.

#include "define.h"

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        vector<bool> isvisited(nums.size() + 1, false);
        for (int i = 0; i < nums.size(); ++i) {
            if (isvisited[nums[i]]) {
                res.push_back(nums[i]);
            } else {
                isvisited[nums[i]] = true;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums{4,3,2,7,8,2,3,1};
    Solution s;
    auto res = s.findDuplicates(nums);
    printVector(res);
    return 0;
}
