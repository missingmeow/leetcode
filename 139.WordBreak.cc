// 139. Word Break

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

#include "define.h"

// 递归查找子串，效率低，主要是每次循环查找耗费大量时间，可以优化
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int pos = std::string::npos;
        for (int i = 0; i < wordDict.size(); ++i) {
            if (s == wordDict[i]) {
                return true;
            }
            pos = s.find(wordDict[i]);
            if (pos == std::string::npos) {
                continue;
            }
            if (wordBreak(s.substr(0, pos), wordDict) && wordBreak(s.substr(pos + wordDict[i].size()), wordDict)) {
                return true;
            }
        }
        return false;
    }
};

// 第一次优化，将字典排序，减少查找时间
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> words(wordDict.begin(), wordDict.end());
        return wordsBreak(s, words, 0);
    }
private:
    bool wordsBreak(string& s, set<string>& words, int start) {
        if (start == s.size()) {
            return true;
        }
        for (int i = start + 1; i <= s.size(); ++i) {
            if (words.find(s.substr(start, i - start)) != words.end() &&
               wordsBreak(s, words, i)) {
                return true;
            }
        }
        return false;
    }
};

// 这里使用了动态规划算法，设计得非常巧妙，使用了一个bool型数组，第 i 个节点表示当前位置之前的字符串能否完成匹配
// 这里实现得要考虑一下，明白之后就会有豁然开朗的感觉
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> match(s.size() + 1, false);
        match[0] = true;
        
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (match[j] && words.find(s.substr(j, i - j)) != words.end()) {
                    match[i] = true;
                    break;
                }
            }
        }
        return match[s.size()];
    }
};
