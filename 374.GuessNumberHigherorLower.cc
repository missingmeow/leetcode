// 374. Guess Number Higher or Lower
// We are playing the Guess Game. The game is as follows:

// I pick a number from 1 to n. You have to guess which number I picked.

// Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

// You call a pre-defined API int guess(int num), which returns 3 possible results:

// -1: The number I picked is lower than your guess (i.e. pick < num).
// 1: The number I picked is higher than your guess (i.e. pick > num).
// 0: The number I picked is equal to your guess (i.e. pick == num).
// Return the number that I picked.

#include "define.h"

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

static int s_pick_num = 1;

int guess(int num) {
    if (num == s_pick_num) return 0;
    if (num < s_pick_num) return 1;
    return -1;
}

class Solution {
public:
    int guessNumber(int n) {
        int min = 1, max = n;
        while (min < max) {
            int temp = min / 2 + max / 2; // 这里不能直接相加再除2，会导致越界
            int res = guess(temp);
            if (res == 0) return temp;
            else if (res < 0) max = temp - 1;
            else min = temp + 1;
        }
        return min;
    }
};
