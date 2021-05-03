# 48. Rotate Image
# You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
# You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
# DO NOT allocate another 2D matrix and do the rotation.

from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix) - 1
        col = int(len(matrix) / 2)
        for i in range(col):
            for j in range(i, n - i):
                x1, y1 = i, j
                tmp = matrix[x1][y1]
                x2, y2 = n - y1, x1
                matrix[x1][y1] = matrix[x2][y2]
                x3, y3 = n - y2, x2
                matrix[x2][y2] = matrix[x3][y3]
                x4, y4 = n - y3, x3
                matrix[x3][y3] = matrix[x4][y4]
                matrix[x4][y4] = tmp

    def print(self, matrix: List[List[int]]) -> None:
        for i in range(0, len(matrix)):
            for j in range(0, len(matrix[i])):
                print(matrix[i][j], end=' ')
            print()


if __name__ == '__main__':
    s = Solution()
    # matrix = [[1]]
    # matrix = [[1,2,3],[4,5,6],[7,8,9]]
    # matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    matrix = [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]
    s.print(matrix)
    s.rotate(matrix)
    s.print(matrix)
