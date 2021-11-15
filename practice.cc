#include "define.h"

class Solution212 {
    enum Direction { left, right, up, down };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (words.empty()) return res;
        if (board.empty()) return res;
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        set<string> sfind(words.begin(), words.end());
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                for (auto iter = sfind.begin(); iter != sfind.end();) {
                    string word = *iter;
                    if (board[i][j] == word[0]) {
                        visit[i][j] = true;
                        if (exist(board, visit, i, j - 1, word, 1, left)
                            || exist(board, visit, i, j + 1, word, 1, right)
                            || exist(board, visit, i - 1, j, word, 1, up)
                            || exist(board, visit, i + 1, j, word, 1, down)) {
                            res.push_back(word);
                            iter = sfind.erase(iter);
                        } else ++iter;
                        visit[i][j] = false;
                    } else ++iter;
                }
            }
        }
        return res;
    }
    bool exist(vector<vector<char>>& board, vector<vector<bool>>& visit, int row, int col, string& word, int pos, Direction direction) {
        if (pos == word.size()) return true;
        if (row < 0 || row >= board.size()) return false;
        if (col < 0 || col >= board[row].size()) return false;
        if (visit[row][col] || board[row][col] != word[pos]) return false;
        bool bcontinue = true;
        visit[row][col] = true;
        if (bcontinue && direction != right && exist(board, visit, row, col - 1, word, pos + 1, left)) bcontinue = false;
        if (bcontinue && direction != left && exist(board, visit, row, col + 1, word, pos + 1, right)) bcontinue = false;
        if (bcontinue && direction != down && exist(board, visit, row - 1, col, word, pos + 1, up)) bcontinue = false;
        if (bcontinue && direction != up && exist(board, visit, row + 1, col, word, pos + 1, down)) bcontinue = false;
        visit[row][col] = false;
        return !bcontinue;
    }
};
