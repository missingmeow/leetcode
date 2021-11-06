// 349. Intersection of Two Arrays
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

#include "define.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> val;
        for (auto& i : nums1) {
            val.insert(i);
        }
        for (auto& i : nums2) {
            if (val.find(i) != val.end()) {
                res.push_back(i);
                val.erase(i);
            }
        }
        return res;
    }
};
