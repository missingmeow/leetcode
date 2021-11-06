// 59. Spiral Matrix II
// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

#include "define.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int left = 0, right = n - 1;
        int bottom = 0, top = n - 1;
        int cur = 1;
        while (left <= right && bottom <= top && cur <= n * n) {
            for (int i = left; i <= right; ++i) {
                res[bottom][i] = cur++;
            }
            ++bottom;
            for (int i = bottom; i <= top; ++i) {
                res[i][right] = cur++;
            }
            --right;
            for (int i = right; i >= left; --i) {
                res[top][i] = cur++;
            }
            --top;
            for (int i = top; i >= bottom; --i) {
                res[i][left] = cur++;
            }
            ++left;
        }
        return res;
    }
};


int main() {
    Solution s;
    auto res = s.generateMatrix(8);

    for (auto& arr : res) {
        for (auto& i : arr) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
