// 441. Arranging Coins
// You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

// Given the integer n, return the number of complete rows of the staircase you will build.

#include "define.h"

 class Solution {
public:
    int arrangeCoins1(int n) {
        int res{};
        int temp = n;
        int cur = 1;
        while (true) {
            temp -= cur;
            ++cur;
            if (temp < 0) break; 
            ++res;
        }
        return res;
    }
    int arrangeCoins(int n) {
        long long temp = n;
        temp *= 2;
        int cur = sqrt(temp);
        temp = (cur + 1) * cur / 2;
        if (temp <= n)
            return cur;
        return cur - 1;
    }
};

int main(int argv, char** argc) {
    Solution s;
    cout << s.arrangeCoins(5) << endl;
    return 0;
}
