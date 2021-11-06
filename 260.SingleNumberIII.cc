// 260. Single Number III
// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 #include "define.h"

 class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 所有数字异或的结果，必定不为0
        int res{};
        for (int& i : nums) {
            res ^= i;
        }
        // 找出第一个为 1 的位
        int cur = 1;
        while ((res & cur) == 0) {
            cur <<= 1;
        }
        // 根据该位的数据把数组分成两组，分别计算各组的异或，得到各组各自的数
        int num1{}, num2{};
        for (int& i : nums) {
            if (i & cur) {
                num1 ^= i;
            } else {
                num2 ^= i;
            }
        }
        return vector<int>{num1, num2};
    }
};

int main(int argv, char** argc) {
    Solution s;
    vector<int> tmp{1,2,1,3,2,5};
    printVector(s.singleNumber(tmp));
    return 0;
}
