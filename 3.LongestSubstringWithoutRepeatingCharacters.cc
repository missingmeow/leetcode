// 3. Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without repeating characters.

#include "define.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxl{};
        int lastl{};
        for (int i = 0; i < s.size(); ++i) {
            for (int j = lastl; j < i; ++j) {
                if (s[i] == s[j]) {
                    lastl = j + 1;
                    break;
                }
            }
            maxl = max(i - lastl + 1, maxl);
        }
        return maxl;
    }
};