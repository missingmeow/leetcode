// 85. Maximal Rectangle
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

#include "define.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int res = 0;
        vector<int> col(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '1') {
                    col[j] += 1;
                } else {
                    col[j] = 0;
                }
            }
            res = max(res, largestRectangleArea(col));
        }
        return res;
    }
private:
    // 这里优化考虑使用 栈 来实现
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] == 0) {
                continue;
            }
            int maxValue = i == 0 ? 0 : heights[i - 1];
            for (int j = heights[i]; j > maxValue; --j) {
                int col = 1;
                for (int k = i + 1; k < heights.size(); ++k) {
                    if (heights[k] >= j) {
                        ++col;
                    } else {
                        break;
                    }
                }
                res = max(res, col * j);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<char>> matrix{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '0', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
        {'1', '0', '1', '0', '0'}
    };
    Solution s;
    cout << s.maximalRectangle(matrix) << endl;
    return 0;
}
