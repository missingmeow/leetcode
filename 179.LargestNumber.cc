// 179. Largest Number
// Given a list of non-negative integers nums, arrange them such that they form the largest number.

// Note: The result may be very large, so you need to return a string instead of an integer.

#include "define.h"

// 仔细思考有个更简单的比较方法 s1 + s2 > s2 + s1
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        vector<string> strs;
        for (int i = 0; i < nums.size(); ++i) {
            strs.push_back(to_string(nums[i]));
        }
        sort(strs.begin(), strs.end(), [](string& s1, string& s2) {
            if (s1.length() == s2.length()) {
                return s1 > s2;
            }
            int size = s1.length() * s2.length();
            int i = 0, j = 0;
            for (int k = 0; k < size; ++i, ++j, ++k) {
                if (i == s1.length()) i = 0;
                if (j == s2.length()) j = 0;
                if (s1[i] != s2[j]) {
                    return s1[i] > s2[j];
                }
            }
            return false;
        });
        for (int i = 0; i < strs.size(); ++i) {
            res += strs[i];
        }
        if (res.length() > 1 && res[0] == '0') {
            return "0";
        }
        return res;
    }
};
