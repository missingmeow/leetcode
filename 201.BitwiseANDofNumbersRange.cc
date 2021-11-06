// 201. Bitwise AND of Numbers Range
// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

#include "define.h"

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // int res = left;
        // for (int i = left + 1; i <= right; i++) {
        //     res &= i;
        // }
        // return res;
        int an = left & right;
        int minus = right - left;
        if (minus > an) return 0;
        int tmp = right - an; // 主要是这步，这个差表示所占的位都是可以为0的，后面只需要把与值这些位置0即可
        int res = 0;
        int i = 0;
        while (tmp) {
            tmp >>= 1;
            res |= (1 << i);
            ++i;
        }
        res = an & ~res;
        return res;
    }
};

int main() {
    Solution s;
    s.rangeBitwiseAnd(5, 7);
    return 0;
}

// 大神的做法
/**
 * Steps:
 * 1) Find the common higher bits
 * 2) Use >> right shift operator for both left and right till bits are not same for both numbers.
 * 3) Use a counter to denote how many times we shifted to the right
 * 4) left shift the left or right variable count number of times.
 * 5) THis pattern holds true for any range
 * @param left
 * @param right
 * @return
 */
int rangeBitwiseAnd(int left, int right) {
    int count=0;
    while(left!=right){
        //right shift both left and right variables till they have common higher bits or they become equal
        left=left>>1;
        right=right>>1;
        count++;// track the count of number of shifts
    }
    return left<<count;// left shift count number of times
}
