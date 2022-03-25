// 378. Kth Smallest Element in a Sorted Matrix
// Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// You must find a solution with complexity better than O(n2).

#include "define.h"


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count{};
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] <= mid) ++count;
                    else break;
                }
            }
            if (count < k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};

int main() {
    vector<vector<int>> temp{vector<int>{1, 4}, vector<int>{2, 5}};
    Solution s;
    cout << s.kthSmallest(temp, 2);
    return 0;
}
