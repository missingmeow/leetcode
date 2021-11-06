// 67. Add Binary
// Given two binary strings a and b, return their sum as a binary string.

#include "define.h"

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty()) return b;
        if (b.empty()) return a;
        string res;
        bool bIn = false;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >=0 && j >= 0) {
            char cur;
            if (a[i] == '0') {
                if (b[j] == '0') {
                    if (bIn) cur = '1';
                    else cur = '0';
                    bIn = false;
                } else {
                    if (bIn) cur = '0';
                    else cur = '1';
                }
            } else {
                if (b[j] == '0') {
                    if (bIn) cur = '0';
                    else cur = '1';
                } else {
                    if (bIn) cur = '1';
                    else cur = '0';
                    bIn = true;
                }
            }
            res = cur + res;
            --i;
            --j;
        }
        string& cur = i >=0 ? a : b;
        int k = i >= 0 ? i : j;
        while (bIn && k >= 0 && cur[k] == '1') {
            res = '0' + res;
            --k;
        }
        if (bIn) {
            res = '1' + res;
            --k;
        }
        if (k >= 0) {
            res = cur.substr(0, k + 1) + res;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.addBinary("11000", "1111") << endl;
    return 0;
}
