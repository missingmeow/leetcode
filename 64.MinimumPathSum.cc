// 64. Minimum Path Sum
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

#include "define.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (i > 0 && j > 0)
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                else if (i > 0)
                    grid[i][j] += grid[i - 1][j];
                else if (j > 0)
                    grid[i][j] += grid[i][j - 1];
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};
