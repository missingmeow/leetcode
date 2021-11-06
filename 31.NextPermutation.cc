// 31. Next Permutation
// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

// The replacement must be in place and use only constant extra memory.

#include "define.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i] <= nums[i - 1]) {
                continue;
            }
            int j = i;
            for (; j < nums.size() - 1; ++j) {
                if (nums[j + 1] <= nums[i - 1]) {
                    break;
                }
            }
            swap(nums[i - 1], nums[j]);
            sort(nums.begin() + i, nums.end()); // 这里有问题，剩下的一定是倒叙的，直接翻转即可，这里导致效率降低
            return;
        }
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            swap(nums[i++], nums[j--]);
        }
    }
};

int main() {
    vector<int> nums{1, 2, 3, 4};
    Solution s;
    for (int i = 0; i < 24; ++i) {
        s.nextPermutation(nums);
        printVector(nums);
    }
    return 0;
}