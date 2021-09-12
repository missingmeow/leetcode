// 4. Median of Two Sorted Arrays
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

#include "define.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) {
            return findMedian(nums2);
        }
        if (nums2.empty()) {
            return findMedian(nums1);
        }
        return findMedian(nums1, nums2);
    }
private:
    double findMedian(vector<int>& nums) {
        size_t size = nums.size();
        if (size & 1) {
            return nums[size / 2];
        } else {
            return (nums[size / 2] + nums[size / 2 -1]) / 2.0;
        }
    }
    double findMedian(vector<int>& nums1, vector<int>& nums2) {
        size_t size = nums1.size() + nums2.size();
        int mid = (size - 1) / 2;
        bool lastNum, isOne = nums1[0] < nums2[0];
        int x = isOne ? 1 : 0, y = isOne ? 0 : 1;
        for (int i = 0; i < size / 2; i++) {
            lastNum = isOne;
            if (x == nums1.size()) {
                isOne = false; y++;
            }
            else if (y == nums2.size()) {
                isOne = true; x++;
            }
            else if (nums1[x] < nums2[y]) {
                isOne = true; x++;
            } else {
                isOne = false; y++;
            }
        }
        double res = isOne ? nums1[x - 1] : nums2[y - 1];
        if (size & 1) {
            return res;
        } else {
            res += lastNum ? nums1[isOne ? x - 2 : x - 1] : nums2[isOne ? y - 1 : y - 2];
            return res / 2;
        }
    }
};


int main(int argc, const char* argv[]) {
    vector<int> nums1{1};
    vector<int> nums2{};
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
