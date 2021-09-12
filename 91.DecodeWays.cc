// 91. Decode Ways
// A message containing letters from A-Z can be encoded into numbers using the following mapping:

// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

// "AAJF" with the grouping (1 1 10 6)
// "KJF" with the grouping (11 10 6)
// Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

// Given a string s containing only digits, return the number of ways to decode it.

// The answer is guaranteed to fit in a 32-bit integer.

#include "define.h"

// 递归，时间不允许
class Solution {
public:
    int numDecodings(string s) {
        int res = 0;
        numDecodings(s, res);
        return res;
    }
private:
    void numDecodings(string s, int& res) {
        if (s.empty()) { 
            ++res;
            return;
        }
        if (s[0] == '0') {
            return;
        }
        numDecodings(s.substr(1), res);
        if (s.length() > 1 && s < "27") {
            numDecodings(s.substr(2), res);
        }
    }
};

class Solution1 {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        if (s[0] == '0') return 0;
        vector<int> nums(s.size(), 0);
        nums[0] = 1;
        if (s.size() > 1) {
            if (s[1] == '0' && s[0] > '2') return 0;
            else if (s[1] == '0') nums[1] = 1;
            else if (s.substr(0, 2) < "27") nums[1] = 2;
            else nums[1] = 1;
        }
        for (int i = 2; i < s.size(); ++i) {
            if (s[i] == '0' && (s[i - 1] == '0' || s[i - 1] > '2')) {
                return 0;
            } else if (s[i] == '0') {
                nums[i] = nums[i - 2];
            } else if (s[i - 1] == '0') {
                nums[i] = nums[i - 1];
            } else {
                nums[i] = nums[i - 1];
                if (s.substr(i - 1, 2) < "27") {
                    nums[i] += nums[i - 2];
                }
            }
        }
        return nums[nums.size() - 1];
    }
};

// 跟方案1相比，只是简单的修改，空间占用 less than 就从 60% 到 90%
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        if (s[0] == '0') return 0;
        int nums[2]{1, 1}, res = 1;
        if (s.size() > 1) {
            if (s[1] == '0' && s[0] > '2') return 0;
            else if (s[1] != '0' && s.substr(0, 2) < "27") nums[1] = 2;
            res = nums[1];
        }
        for (int i = 2; i < s.size(); ++i) {
            if (s[i] == '0' && (s[i - 1] == '0' || s[i - 1] > '2')) {
                return 0;
            } else if (s[i] == '0') {
                res = nums[0];
            } else if (s[i - 1] == '0') {
                res = nums[1];
            } else {
                res = nums[1];
                if (s.substr(i - 1, 2) < "27") {
                    res += nums[0];
                }
            }
            nums[0] = nums[1];
            nums[1] = res;
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution1 s;
    cout << s.numDecodings("1") << endl;
    cout << s.numDecodings("11") << endl;
    cout << s.numDecodings("1101") << endl;
    cout << s.numDecodings("11101") << endl;
    cout << s.numDecodings("111101") << endl;
    return 0;
}

