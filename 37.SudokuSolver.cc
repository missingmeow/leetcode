// 37. Sudoku Solver
// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

#include "define.h"

class Solution1 {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool bContinue = true;
        while (bContinue) {
            bContinue = false;
            for (int row = 0; row < board.size(); ++row) {
                for (int col = 0; col < board[row].size(); ++col) {
                    if (board[row][col] == '.' && !verify(board, row, col)) {
                        bContinue = true;
                    }
                }
            }
        }
    }
private:
    bool verify(vector<vector<char>>& board, int row, int col) {
        set<char> cur{'1','2','3','4','5','6','7','8','9'};
        // row
        for (int i = 0; i < board[row].size(); ++i) {
            if (board[row][i] == '.') continue;
            cur.erase(board[row][i]);
        }
        // col
        for (int j = 0; j < board.size(); ++j) {
            if (board[j][col] == '.') continue;
            cur.erase(board[j][col]);
        }
        // grid
        int m = row / 3, n = col / 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[m * 3 + i][n * 3 + j] == '.') continue;
                cur.erase(board[m * 3 + i][n * 3 + j]);
            }
        }
        // only one, write it
        if (cur.size() == 1) {
            board[row][col] = *cur.begin();
            return true;
        }
        // check other two rows and cols have it then write it
        for (auto iter = cur.begin(); iter != cur.end(); ++iter) {
            int rowmatch{}, colmatch{};
            for (int i = 0; i < 3; ++i) {
                if (m * 3 + i == row) continue;
                if (board[m * 3 + i][col] == '.') {
                    --colmatch;
                }
                for (int j = 0; j < board[row].size(); ++j) {
                    if (board[m * 3 + i][j] == *iter) {
                        ++rowmatch;
                        break;
                    }
                }
            }
            for (int i = 0; i < 3; ++i) {
                if (n * 3 + i == col) continue;
                if (board[row][n * 3 + i] == '.') {
                    --rowmatch;
                }
                for (int j = 0; j < board[row].size(); ++j) {
                    if (board[j][n * 3 + i] == *iter) {
                        ++colmatch;
                        break;
                    }
                }
            }
            if (rowmatch == 2 || colmatch == 2) {
                board[row][col] = *iter;
                return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }
private:
    bool solveSudoku(vector<vector<char>>& board, int row, int col) {
        if (col == 9) { ++row; col = 0; }
        if (row == 9) return true;
        if (board[row][col] != '.') {
            return solveSudoku(board, row, col + 1);
        }
        for (int i = 1; i <= 9; ++i) {
            if (isValid(board, row, col, i)) {
                board[row][col] = '0' + i;
                if (solveSudoku(board, row, col + 1)) {
                    return true;
                }
            }
        }
        board[row][col] = '.';
        return false;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, int val) {
        char cc = '0' + val;
        // row
        for (int i = 0; i < board[row].size(); ++i) {
            if (board[row][i] == cc) return false;
        }
        // col
        for (int j = 0; j < board.size(); ++j) {
            if (board[j][col] == cc) return false;
        }
        // grid
        int m = row / 3, n = col / 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[m * 3 + i][n * 3 + j] == cc) return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> temp { // 按规则来推算到中间就不符合规则了，只能递归来算
        vector<char>{'.','.','9','7','4','8','.','.','.'},
        vector<char>{'7','.','.','.','.','.','.','.','.'},
        vector<char>{'.','2','.','1','.','9','.','.','.'},
        vector<char>{'.','.','7','.','.','.','2','4','.'},
        vector<char>{'.','6','4','.','1','.','5','9','.'},
        vector<char>{'.','9','8','.','.','.','3','.','.'},
        vector<char>{'.','.','.','8','.','3','.','2','.'},
        vector<char>{'.','.','.','.','.','.','.','.','6'},
        vector<char>{'.','.','.','2','7','5','9','.','.'}
    };
    
    vector<vector<char>> temp1 {
        vector<char>{'5','3','.','.','7','.','.','.','.'},
        vector<char>{'6','.','.','1','9','5','.','.','.'},
        vector<char>{'.','9','8','.','.','.','.','6','.'},
        vector<char>{'8','.','.','.','6','.','.','.','3'},
        vector<char>{'4','.','.','8','.','3','.','.','1'},
        vector<char>{'7','.','.','.','2','.','.','.','6'},
        vector<char>{'.','6','.','.','.','.','2','8','.'},
        vector<char>{'.','.','.','4','1','9','.','.','5'},
        vector<char>{'.','.','.','.','8','.','.','7','9'}
    };
    Solution s;
    s.solveSudoku(temp);
    for (auto& i : temp) {
        printVector(i);
    }
    return 0;
}