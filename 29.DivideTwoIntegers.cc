// 29. Divide Two Integers
// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// Return the quotient after dividing dividend by divisor.

// The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, assume that your function returns 231 − 1 when the division result overflows.

#include "define.h"

// 纯减法实现会超时，必须了解计算机的加减乘除的实现
class Solution1 {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            return -dividend;
        }
        bool bnagetive = false;
        long long udividend = dividend, udivisor = divisor;
        if (dividend < 0) {
            bnagetive = !bnagetive;
            udividend = -udividend;
        } else {
            udividend = dividend;
        }
        if (divisor < 0) {
            bnagetive = !bnagetive;
            udivisor = -udivisor;
        }
        int res = 0;
        while (udividend >= udivisor) {
            udividend -= udivisor;
            ++res;
        }
        if (bnagetive)
            return -res;
        return res;
    }
};

// 正数 和 0 的补码就是其本身，也就是原码，也是反码
// 负数的补码，负数的原码（第一位为1表示负号，其余和正数原码一样）除符号位各位取反 再 加1，一个特殊情况：使用[1000 0000]代表-128，但-128不存在原码
// 这样加减法就已经可以完成了，直接 二进制 位相加即可

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long lldividend{dividend};
        long long lldivisor{divisor};
        bool bNegative{false};
        if (lldividend < 0) {
            bNegative = !bNegative;
            lldividend = -lldividend;
        }
        if (lldivisor < 0) {
            bNegative = !bNegative;
            lldivisor = -lldivisor;
        }
        stack<int> s;
        while (lldividend) {
            s.push(lldividend & 1);
            lldividend >>= 1;
        }
        long long res = 0;
        long long ans = 0;
        while(!s.empty()) {
            int cur = s.top();
            s.pop();
            res <<= 1;
            res += cur;
            ans <<= 1;
            if (res < lldivisor) {
                continue;
            } else {
                res -= lldivisor;
                ans += 1;
            }
        }
        if (bNegative) {
            ans = -ans;
            if (ans < INT_MIN) ans = INT_MIN;
        } else if (ans > INT_MAX) {
            ans = INT_MAX;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << INT_MIN << s.divide(INT_MIN, -1) << endl;
    return 0;
}
