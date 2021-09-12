// 42. Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

#include "define.h"

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int i = 0, res = 0;
        while (i < height.size() && height[i] == 0) { i++; }
        int left = i++;
        int right = -1;
        for (; i < height.size(); i++) {
            if (height[i] >= height[left]) {
                if (left + 1 < i) {
                    for (int j = left + 1; j < i; j++) {
                        res += height[left] - height[j];
                    }
                }
                left = i;
                right = -1;
            } else if (right == -1 || height[i]  > height[right]) {
                right = i;
            }
            if (i == height.size() - 1) {
                if (right > left && height[right] != 0) {
                    for (int j = left + 1; j < right; j++) {
                        res += height[right] - height[j];
                    }
                    i = right;
                    left = right;
                    right = -1;
                }
            }
        }
        return res;
    }
};

// 优化 O(n) ，以最低的高度计算能储存的水量
class Solution1 {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                res += (leftMax - height[left]);
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                res += (rightMax - height[right]);
                right--;
            }
        }
        return res;
    }
};

int main() {
    vector<int> num{4,2,0,3,2,5};
    Solution1 s;
    cout << s.trap(num) << endl;
    return 0;
}
