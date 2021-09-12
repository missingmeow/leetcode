// 84. Largest Rectangle in Histogram
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

#include "define.h"

// 能解决，但运算速度很慢，提示 Time Limit Exceeded
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        if (heights.empty())
            return 0;
        int res = heights[0];
        for (auto i = 1; i <= heights.size(); ++i)
        {
            if (i < heights.size() && heights[i] >= heights[i - 1])
            {
                continue;
            }
            int minimum = heights[i - 1];
            for (auto j = i - 1; j >= 0; --j)
            {
                minimum = min(minimum, heights[j]);
                if (minimum == 0)
                {
                    break;
                }
                res = max(res, (i - j) * minimum);
            }
        }
        return res;
    }
};

// 使用栈，每次入栈的元素都要保证当前栈顶的元素对应的值要小于等于当前值
// 这样后续出栈时即可直接计算以栈顶的值为高度，与下个栈顶值为长度之间的面积
class Solution1
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int res = 0;
        stack<int> s;
        int i = 0;
        for (; i < heights.size(); ++i)
        {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int cur = s.top();
                s.pop();

                if (s.empty()) {
                    res = max(res, heights[cur] * i);
                } else {
                    res = max(res, heights[cur] * (i - s.top() - 1));
                }
            }
            s.push(i);
        }
        while (!s.empty()) {
            int cur = s.top();
            s.pop();

            if (s.empty()) {
                res = max(res, heights[cur] * i);
            } else {
                res = max(res, heights[cur] * (i - s.top() - 1));
            }
        }
        return res;
    }
};

int main(int argc, const char **argv)
{
    vector<int> heights{3, 1, 3, 1, 2};
    Solution1 s;
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}