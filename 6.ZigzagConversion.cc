// 6. Zigzag Conversion
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);

#include "define.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<vector<char>> arr;
        int pos = 0 ;
        bool direction = true;
        vector<char> row(numRows, 0);
        for (int i = 0; i < s.size(); ++i) {
            row[pos] = s[i];
            if (direction) {
                if (pos == numRows - 1) {
                    arr.push_back(row);
                    row.clear();
                    row.resize(numRows, 0);
                    direction = !direction;
                    --pos;
                } else {
                    ++pos;
                }
            } else if (pos == 0) {
                ++pos;
                direction = !direction;
            } else {
                --pos;
                arr.push_back(row);
                row.clear();
                row.resize(numRows, 0);
            }
        }
        arr.push_back(row);
        string res;
        for (int i = 0; i < arr[0].size(); ++i) {
            for (int j = 0; j < arr.size(); ++j) {
                if (arr[j][i] != 0) res += arr[j][i];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    return 0;
}