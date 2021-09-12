// 200. Number of Islands
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

#include "define.h"

// 参考别人的做法，有时候真的可以多考虑一下借用辅助内存考虑一下，刚开始考虑的方向就不对
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> isVisit(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1' && !isVisit[i][j]) {
                    dfs(grid, isVisit, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int i, int j) {
        if (i < 0 || i >= grid.size()) return;
        if (j < 0 || j >= grid[i].size()) return;
        if (visit[i][j] || grid[i][j] == '0') return;
        visit[i][j] = true;
        dfs(grid, visit, i - 1, j);
        dfs(grid, visit, i + 1, j);
        dfs(grid, visit, i, j - 1);
        dfs(grid, visit, i, j + 1);
    }
};
