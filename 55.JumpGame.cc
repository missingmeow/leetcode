// 55. Jump Game
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.

#include "define.h"

// 贪心算法著名案例
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return true;

        int maxIndex = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (i > maxIndex) return false;
            maxIndex = max(maxIndex, nums[i] + i);
        }
        return true;
    }
};

int main(int argc, const char** argv) {
    vector<int> nums{3,2,1,0,4};
    Solution s;
    cout << s.canJump(nums) << endl;
    return 0;
}
