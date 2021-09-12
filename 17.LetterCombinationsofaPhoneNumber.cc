// 17. Letter Combinations of a Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// 2 - abc 3 - def ... 7 - pqrs 8 - tuv 9 - wxzy
#include "define.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        recursion(digits, "", res);
        return res;
    }
private:
    void recursion(string digits, string cur, vector<string>& res) {
        if (digits.empty()) {
            if (!cur.empty())
                res.push_back(cur);
            return;
        }
        string ch = num2string(digits[0] - '0');
        string sub = digits.substr(1, digits.size() - 1);
        for (int i = 0; i < ch.size(); i++) {
            recursion(sub, cur + ch[i], res);
        }
    }
    string num2string(int num) {
        string res;
        if (num <= 7) {
            for (int i = 0; i < 3; i++) {
                res += (num - 2) * 3 + 'a' + i;
            }
            if (num == 7) {
                res += (num - 2) * 3 + 'a' + 3;
            }
        } else {
            for (int i = 0; i < 3; i++) {
                res += (num - 2) * 3 + 'b' + i;
            }
            if (num == 9) {
                res += (num - 2) * 3 + 'b' + 3;
            }
        }
        return res;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    auto res = s.letterCombinations("9");
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}
