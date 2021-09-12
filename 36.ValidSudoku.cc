// 36. Valid Sudoku
// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.


#include "define.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> row;
        vector<set<char>> col(9, set<char>());
        vector<set<char>> mid(3, set<char>());
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (row.find(board[i][j]) != row.end() ||
                   col[j].find(board[i][j]) != col[j].end() ||
                   mid[j / 3].find(board[i][j]) != mid[j / 3].end()) {
                    return false;
                }
                row.insert(board[i][j]);
                col[j].insert(board[i][j]);
                mid[j / 3].insert(board[i][j]);
            }
            row.clear();
            if (i % 3 == 2) {
                mid[0].clear(); mid[1].clear(); mid[2].clear();
            }
        }
        return true;
    }
};
