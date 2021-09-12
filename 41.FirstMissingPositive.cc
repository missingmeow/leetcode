// 41. First Missing Positive
// Given an unsorted integer array nums, return the smallest missing positive integer.
// You must implement an algorithm that runs in O(n) time and uses constant extra space.

#include "define.h"

// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int num = 1;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] <= 0)
//                 continue;
//             if (i > 0 && nums[i] == nums[i - 1])
//                 continue;
//             if (nums[i] != num)
//                 return num;
//             num++;
//         }
//         return num;
//     }
// };
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int count = nums.size();
        int index = 1;
        for (int i = 0; i < count; i++, index++) {
            if (nums[i] == index || nums[i] <= 0 || nums[i] >= count) {
                continue;
            }
            int newIndex = nums[i] - 1;
            if (nums[newIndex] == nums[i]) {
                continue;
            }
            int tmp = nums[newIndex];
            nums[newIndex] = nums[i];
            nums[i] = tmp;
            i--;
        }
        index = 1;
        for (int i = 0; i < nums.size(); i++, index++) {
            if (nums[i] != index) {
                return index;
            }
        }
        return index;
    }
};

int main(int argc, const char* argv[])
{
    vector<int> nums{3,4,-1,1,2};
    Solution s;
    cout << s.firstMissingPositive(nums) << endl;
    return 0;
}
