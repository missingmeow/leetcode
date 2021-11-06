// 79. Word Search
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

#include "define.h"

class Solution {
    enum Direction { left, right, up, down };
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty()) return false;
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    visit[i][j] = true;
                    if (exist(board, visit, i, j - 1, word, 1, left)
                        || exist(board, visit, i, j + 1, word, 1, right)
                        || exist(board, visit, i - 1, j, word, 1, up)
                        || exist(board, visit, i + 1, j, word, 1, down))
                        return true;
                    visit[i][j] = false;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, vector<vector<bool>>& visit, int row, int col, string& word, int pos, Direction direction) {
        if (pos == word.size()) return true;
        if (row < 0 || row >= board.size()) return false;
        if (col < 0 || col >= board[row].size()) return false;
        if (visit[row][col] || board[row][col] != word[pos]) return false;
        visit[row][col] = true;
        if (direction != right && exist(board, visit, row, col - 1, word, pos + 1, left)) return true;
        if (direction != left && exist(board, visit, row, col + 1, word, pos + 1, right)) return true;
        if (direction != down && exist(board, visit, row - 1, col, word, pos + 1, up)) return true;
        if (direction != up && exist(board, visit, row + 1, col, word, pos + 1, down)) return true;
        visit[row][col] = false;
        return false;
    }
};

int main() {
    vector<vector<char>> tmp(3, vector<char>(4, 'a'));
    Solution s;
    cout << s.exist(tmp, "aaaaaaaaaaaaa") << endl;
    return 0;
}
