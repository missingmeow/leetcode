// 50. Pow(x, n)
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

#include "define.h"

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        long long ln = n;
        long long count = ln > 0 ? ln : -ln;
        double c = x;
        double r = 1.0;
        while (count) {
            if (count & 1) {
                r *= c;
            }
            count >>= 1;
            if (count) {
                c *= c;
            }
        }
        if (n > 0) {
            return r;
        } else {
            return 1 / r;
        }
    }
};

int main() {
    Solution s;
    cout << s.myPow(10, 8);
    return 0;
}
