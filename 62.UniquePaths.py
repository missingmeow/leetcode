# 62. Unique Paths
# A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
# The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
# How many possible unique paths are there?
from typing import List


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # 内存和运行时间优化
        arr = [1] * n
        for i in range(1, m):
            for j in range(1, n):
                arr[j] = arr[j] + arr[j - 1]
        return arr[n - 1]

        # arr = []
        # for i in range(m):
        #     arr.append([])
        #     for j in range(n):
        #         if j - 1 < 0 and i - 1 < 0:
        #             arr[i].append(1)
        #         elif j - 1 < 0:
        #             arr[i].append(arr[i - 1][j])
        #         elif i - 1 < 0:
        #             arr[i].append(arr[i][j - 1])
        #         else:
        #             arr[i].append(arr[i][j - 1] + arr[i - 1][j])
        # return arr[m-1][n-1]
        # 递归不可取
        # return self.run(0, 0, m-1, n-1)

    def run(self, x: int, y: int, m: int, n: int) -> int:
        if x > n or y > m:  # 此路不通
            return 0
        if x == n and y == m:
            return 1
        return self.run(x+1, y, m, n) + self.run(x, y+1, m, n)


if __name__ == '__main__':
    s = Solution()
    print(s.uniquePaths(3, 7))
    print(s.uniquePaths(3, 2))
    print(s.uniquePaths(7, 3))
    print(s.uniquePaths(3, 3))
    print(s.uniquePaths(23, 53))  # 3648677478873075576
