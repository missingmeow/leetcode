// 54.  Spiral Matrix

// Given an m x n matrix, return all elements of the matrix in spiral order.

#include "define.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        res.reserve(matrix.size() * matrix[0].size());
        int len = min(matrix.size(), matrix[0].size());
        len = len / 2 + (len & 1 ? 1 : 0);
        for (int i = 0; i < len; ++i) {
            int row = i, col = i;
            for (; col < matrix[0].size() - i && row < matrix.size() - i; ++col) { // 列 👉
                res.push_back(matrix[row][col]);
            }
            for (--col, ++row; row < matrix.size() - i && col < matrix[0].size() - i; ++row) { // 行 👇
                res.push_back(matrix[row][col]);
            }
            bool bchange = false;
            for (--row, --col; col >= i && row > i; --col) {
                bchange = true;
                res.push_back(matrix[row][col]);
            }
            for (++col, --row; row > i && bchange; --row) {
                res.push_back(matrix[row][col]);
            }
        }
        return res;
    }
};


// 看了一下别人的方案，使用四个变量指定四个方向的索引更加简单易懂

int main() {
    vector<vector<int>> arr{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    // vector<vector<int>> arr{{1}, {2}, {3}};
    // vector<vector<int>> arr{{2,5,8},{4,0,-1}};
    // vector<vector<int>> arr{{1,2}, {3,4}, {5, 6}, {7, 8}};
    Solution s;
    auto res = s.spiralOrder(arr);
    for (auto&& i : res) {
        cout <<  i << " ";
    }
    return 0;
}

