// 43. Multiply Strings
// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include "define.h"


class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0") return num1;
        if (num2 == "0") return num2;
        if (num2.size() > num1.size()) swap(num1, num2);
        string res{};
        for (int i = num2.size(); i >= 1; --i) {
            string tmp = num1 + string(i - 1, '0');
            int times = num2[num2.size() - i] - '0';
            while (times--) {
                res = add(res, tmp);
            }
        }
        return res;
    }
    string add(string num1, string num2) {
        int len = num1.size() > num2.size() ? num1.size() : num2.size();
        if (num1.size() != len) num1 = string(len - num1.size(), '0') + num1;
        if (num2.size() != len) num2 = string(len - num2.size(), '0') + num2;
        string res(len, '0');
        bool bIn = false;
        for (int i = len - 1; i >= 0; --i) {
            int cur = (num1[i] - '0') + (num2[i] - '0');
            if (bIn) ++cur;
            bIn = cur > 9;
            cur %= 10;
            res[i] = cur + '0';
        }
        if (bIn) res = "1" + res;
        return res;
    }
};

int main() {
    Solution s;
    cout << s.multiply("123", "456");
    return 0;
}
