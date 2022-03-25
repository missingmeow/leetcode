// 62. Unique Paths
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

#include "define.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> arr(m, vector<int>(n, 0));
        arr[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j < n - 1)
                    arr[i][j + 1] += arr[i][j];
                if (i < m - 1)
                    arr[i + 1][j] += arr[i][j];
            }
        }
        return arr[m -1][n - 1];
    }
};