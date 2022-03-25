// 81. Search in Rotated Sorted Array II
// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

// You must decrease the overall operation steps as much as possible.

#include "define.h"

// 与 33 题不一样的是这个数组是会有重复值的
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
    bool search(vector<int>& nums, int left, int right, int target) {
        while (left < right && nums[left] == nums[left + 1]) { ++left; }
        while (left < right && nums[right] == nums[right - 1]) { --right; }
        if (left > right) return false;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (mid == left) {
            return search(nums, mid + 1, right, target);
        }
        if (nums[mid] > nums[left]) { // left sort
            if (target >= nums[left] && target < nums[mid]) {
                return search(nums, left, mid - 1, target);
            } else {
                return search(nums, mid + 1, right, target);
            }
        } else { // right sort
            if (target > nums[mid] && target <= nums[right]) {
                return search(nums, mid + 1, right, target);
            } else {
                return search(nums, left, mid - 1, target);
            }
        }
    }
};
