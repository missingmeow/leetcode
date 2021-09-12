// 120. Triangle
// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

#include "define.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) {
            return 0;
        }
        vector<int> vec(triangle.size(), 0);
        for (int i = 0; i < triangle.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == 0) {
                    vec[j] += triangle[i][j];
                } else if (j == i) {
                    vec[j] = vec[j - 1] + triangle[i][j];
                } else {
                    vec[j] = min(vec[j], vec[j - 1]) + triangle[i][j];
                }
            }
        }
        int res = vec[0];
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i] < res) {
                res = vec[i];
            }
        }
        return res;
    }
};

int main(int argc, const char** argv) {
    vector<vector<int>> triangle;
    // triangle.push_back({2});
    // triangle.push_back({3, 4});
    // triangle.push_back({6, 5, 7});
    // triangle.push_back({4, 1, 8, 3});
    triangle.push_back({-11});
    Solution s;
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}