// 350. Intersection of Two Arrays II
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

#include "define.h"

class Solution {
public:
    vector<int> intersect(vector<int>&& nums1, vector<int>&& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            while (i < nums1.size() && nums1[i] < nums2[j]) ++i;
            if (i == nums1.size()) break;
            while (j < nums2.size() && nums2[j] < nums1[i]) ++j;
            if (j == nums2.size()) break;
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i; ++j;
            }
        }
        return res;
    }
};

// 使用 unordered_map 会是更好的解法

int main() {
    Solution s;
    auto res = s.intersect({1, 1}, {1, 2});
    for (auto& i : res) {
        cout << i << " ";
    }
}
