// 668. Kth Smallest Number in Multiplication Table
// Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

// Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.

#include "define.h"

class Solution1 {
public:
    int findKthNumber(int m, int n, int k) {
        vector<int> arr(m * n + 1, 0);
        int index{1};
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                arr[index] = i * j;
                ++index;
            }
        }

        int left = 1, right = m * n;
        while (true) {
            int mid = left + (right - left) / 2;
            int midval = arr[mid];
            while (left < right) {
                while (left < right && arr[right] > midval) --right;
                while (left < right && arr[left] <= midval) ++left;
                if (left < right) {
                    swap(arr[left], arr[right]);
                    --right;
                }
            }
            swap(arr[left], arr[mid]);
            if (left == k)
                return arr[left];
            else if (left < k) {
                left = left + 1;
                right = m * n;
            } else {
                right = left - 1;
                left = 1;
            }
        }
    }
};

// 这题解法有个疑问，为什么一直取平均数最后能保证是乘法表中的某个乘积
// 这里需要好好思考一下，因为是两个数向中间逼近，其实最后一定是那个数才会有 low == high
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n;
        while(low < high) {
            int mid = low + (high - low) / 2;
            // 需要遍历每一行，计算当前所有比该数小的个数
            int count{};
            for (int i = 1; i <= m; ++i) {
                count += min(mid / i, n);
            }
            if (count >= k) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};

int main() {
    Solution s;
    cout << s.findKthNumber(3, 3, 7);
    return 0;
}