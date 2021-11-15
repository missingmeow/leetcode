// 739. Daily Temperatures

// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

#include "define.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> s;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!s.empty()) {
                int last = s.top();
                if (temperatures[i] > temperatures[last]) {
                    ans[last] = i - last;
                    s.pop();
                } else {
                    break;
                }
            }
            s.push(i);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> temp{73,74,75,71,69,72,76,73};
    printVector(s.dailyTemperatures(temp));
    return 0;
}
