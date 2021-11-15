// 7. Reverse Integer
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

#include "define.h"

class Solution {
public:
    int reverse(int x) {
        bool bNegative = x < 0;
        int divide = bNegative ? -(INT_MIN / 10) : INT_MAX / 10;
        int mod = bNegative ? -(INT_MIN % 10) : INT_MAX % 10;
        int res{};
        int tmp{x};
        while (tmp) {
            if (res > divide || (res == divide && (bNegative ? -tmp : tmp) > mod)) return 0;
            int mo = tmp % 10;
            res *= 10;
            res += bNegative ? -mo : mo;
            tmp /= 10;
        }
        return bNegative ? -res : res;
    }
};

int main() {
    Solution s;
    cout << s.reverse(INT_MIN);
    return 0;
}