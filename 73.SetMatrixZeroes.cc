// 73. Set Matrix Zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

// You must do it in place.

#include "define.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> colzero(matrix.size(), false);
        for (int i = 0; i < matrix.size(); ++i) {
            bool rowzero = false;
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    if (!colzero[j]) { // 第一次遇到 0 的列，往回改数据
                        colzero[j] = true;
                        for (int k = 0; k < i; ++k) {
                            matrix[k][j] = 0;
                        }
                    }
                    rowzero = true;
                } else if (colzero[j]) {
                    matrix[i][j] = 0;
                }
            }
            if (rowzero) {
                for (int k = 0; k < matrix[i].size(); ++k) {
                    matrix[i][k] = 0;
                }
            }
        }
    }
};
