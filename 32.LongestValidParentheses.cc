// 32. Longest Valid Parentheses
// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

#include "define.h"


class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        vector<int> times(s.size(), 0);
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                if (st.empty()) {
                    continue;
                }
                int pair = st.top(); st.pop();
                times[i] = i - pair + 1;
                if (pair > 0 && s[pair - 1] == ')') {
                    times[i] += times[pair - 1];
                }
                maxlen = max(maxlen, times[i]);
            }
        }
        return maxlen;
    }
};

// 上面好像数组有点多余，优化一下
class Solution1 {
public:
    int longestValidParentheses(string s) {
        int maxres{};
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // 可以理解为最后一个不匹配的值 ，i (计算时中间这段匹配) i+n
                } else {
                    maxres = max(maxres, i - st.top());
                }
            }
        }
        return maxres;
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses(")()((((()())");
    return 0;
}
