// 15. 3Sum
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

#include "define.h"

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> res;
//         int lastNum;
//         for (int i = 0; i < nums.size(); i++) {
//             int target = -nums[i];
//             if (target < 0) {
//                 break;
//             }
//             if (i != 0 && lastNum == nums[i]) {
//                 continue;
//             }
//             lastNum = nums[i];
//             set<int> secNum, thirdNum;
//             for (int j = i + 1; j < nums.size(); j++) {
//                 if (thirdNum.find(nums[j]) != thirdNum.end()) {
//                     if (secNum.find(nums[j]) == secNum.end()) {
//                         res.push_back({nums[i], - nums[i] - nums[j], nums[j]});
//                         secNum.insert(nums[j]);
//                     }
//                 } else {
//                     thirdNum.insert(target - nums[j]);
//                 }
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 看到一个更好的思路，排序后，使用两个指针从前后移动，计算
        vector<vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = i + 1;
        int k = nums.size() - 1;
        while (nums[i] <= 0 && i < nums.size() - 2) { // 排序过后，最小的值不能大于0
            int tmp = nums[i] + nums[j];
            if (tmp == -nums[k]) {
                res.push_back({nums[i], nums[j], nums[k]});
                while(true) {
                    j++;
                    if (j >= k || nums[j] != nums[j - 1]) {
                        break;
                    }
                }
                while(true) {
                    k--;
                    if (j >= k || nums[k] != nums[k + 1]) {
                        break;
                    }
                }
            }
            else if (tmp < -nums[k]) { // 负数大，向右移动
                while(true) {
                    j++;
                    if (j >= k || nums[j] != nums[j - 1]) {
                        break;
                    }
                }
            }
            else { // 正数大，向左移动
                while(true) {
                    k--;
                    if (j >= k || nums[k] != nums[k + 1]) {
                        break;
                    }
                }
            }
            if (j >= k) {
                while(true) {
                    i++;
                    if (i >= nums.size() - 2 || nums[i] != nums[i - 1]) {
                        break;
                    }
                }
                j = i + 1;
                k = nums.size() - 1;
            }
        }
        return res;
    }
};

int main(int argc, const char* argv[]) {
    vector<int> nums{-2,0,0,2,2};
    Solution s;
    auto res = s.threeSum(nums);
    for (auto i : res) {
        cout << i[0] << " " << i[1] << " " << i[2] << endl;
    }
    return 0;
}
