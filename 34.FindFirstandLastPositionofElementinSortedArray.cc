// 34. Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

#include "define.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        if (nums.empty()) return res;
        int left = 0;
        int right = nums.size() - 1;
        bool lfind = nums[left] == target;
        if (lfind) res[0] = left;
        while (!lfind && left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target && mid - 1 >= 0 && nums[mid - 1] < target) {
                    res[0] = mid;
                    lfind = true;
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (!lfind && left == right && nums[left] == target) {
            res[0] = left;
        }
        left = 0;
        right = nums.size() - 1;
        bool rfind = nums[right] == target;
        if (rfind) res[1] = right;
        while (!rfind && left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target && mid + 1 < nums.size() && nums[mid + 1] > target) {
                    res[1] = mid;
                    rfind = true;
                }
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (!rfind && left == right && nums[right] == target) {
            res[1] = right;
        }
        return res;
    }
};

int main() {
    vector<int> temp{1, 2, 3};
    Solution s;
    s.searchRange(temp, 1);
    return 0;
}