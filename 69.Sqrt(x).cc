// 69. Sqrt(x)
// Given a non-negative integer x, compute and return the square root of x.

// Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

// Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

#include "define.h"

class Solution {
public:
    int mySqrt(int x) {
        long long left = 0, right = x;
        while (left < right) {
            long long mid = (left + right) / 2;
            if (mid * mid > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left * left > x) return left - 1;
        return left;
    }
};