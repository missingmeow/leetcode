// 49. Group Anagrams
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

#include "define.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, int> match;
        for (int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (match.find(str) == match.end()) {
                int index = match.size();
                if (res.size() < index + 1) {
                    res.resize(index + 1, vector<string>());
                }
                match[str] = index;
            }
            res[match[str]].push_back(strs[i]);
        }
        return res;
    }
};

