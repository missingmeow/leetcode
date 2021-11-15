// 368. Largest Divisible Subset
// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

#include "define.h"


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> times(nums.size(), 0);
        vector<int> pos(nums.size(), -1);
        int maxpos{0};
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && times[i] < times[j] + 1) {
                    times[i] = times[j] + 1;
                    pos[i] = j;
                    if (maxpos == -1) maxpos = i;
                    if (times[i] > times[maxpos]) maxpos = i;
                }
            }
        }
        vector<int> res;
        while (maxpos != -1) {
            res.push_back(nums[maxpos]);
            maxpos = pos[maxpos];
        }
        return res;
    }
};

int main() {
    vector<int> temp{4,8,10,240};
    Solution s;
    auto res = s.largestDivisibleSubset(temp);
    printVector(res);
    return 0;
}
