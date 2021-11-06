// 279. Perfect Squares
// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

#include "define.h"

class Solution {
public:
    // 递归，耗时太多
    // int numSquares(int n) {
    //     int res{n};
    //     for (int i = 2; i * i <= n; ++i) {
    //         int temp = n - i * i;
    //         if (temp == 0) return 1;
    //         int times = numSquares(temp);
    //         res = min(times + 1, res);
    //     }
    //     return res;
    // }
    int numSquares(int n) {
        vector<int> times(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; i - 1 + j * j <= n; ++j) {
                int cur = times[i - 1] + 1;
                if (times[i - 1 + j * j] != 0 && times[i - 1 + j * j] < cur)
                    continue;
                times[i - 1 + j * j] = cur;
            }
        }
        return times[n];
    }
    // 优化，好像并没有 囧rz
    int numSquares1(int n) {
        vector<int> square(100, 0);
        for (int i = 1; i <= square.size(); ++i) {
            square[i - 1] = i * i;
        }
        vector<int> times(n + 1, INT_MAX);
        times[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < square.size(); ++j) {
                if (square[j] > i) break;
                times[i] = min(times[i], times[i - square[j]] + 1);
            }
        }
        return times[n];
    }
};

int main() {
    Solution s;
    cout << s.numSquares1(9);
    return 0;
}