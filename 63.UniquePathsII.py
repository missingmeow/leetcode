# 63. Unique Paths II
# A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
# The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
# Now consider if some obstacles are added to the grids. How many unique paths would there be?
# An obstacle and space is marked as 1 and 0 respectively in the grid.
from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        arr = []
        obs = 1
        for i in range(0, n):
            if obstacleGrid[0][i] == 1 and obs == 1:
                obs = 0
            arr.append(obs)
        obs = 1 if obstacleGrid[0][0] == 0 else 0
        for i in range(1, m):
            if obstacleGrid[i][0] == 1 and obs == 1:
                obs = 0
            arr[0] = obs
            for j in range(1, n):
                if obstacleGrid[i][j] == 1:
                    arr[j] = 0
                else:
                    arr[j] = arr[j] + arr[j - 1]
        return arr[n - 1]


if __name__ == '__main__':
    s = Solution()
    obstacleGrid = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
    # obstacleGrid = [[0,1],[0,0]]
    # obstacleGrid = [[1,0]]
    # obstacleGrid = [[0],[1]]
    # obstacleGrid = [[1],[0]]
    print(s.uniquePathsWithObstacles(obstacleGrid))
