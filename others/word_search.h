
#include "common.h"

class Solution {
public:
    typedef vector<vector<char> > board_type;
    typedef vector<vector<bool> > ub_type;

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word.length() == 0)
            return true;

        ub_type ub;
        ub.reserve(board.size());
        for (size_t i = 0; i < board.size(); i++) {
            ub.push_back(vector<bool>());
            for (size_t j = 0; j < board[0].size(); j++) {
                ub[i].push_back(false);
            }
        }

        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (exist(board, ub, i, j, word))
                    return true;
            }
        }
        return false;
    }

    bool exist(board_type &board, ub_type &ub,
        int row, int col, string word) {
        if (word.length() == 0)
            return true;
        if (row > board.size()-1 || col > board[0].size()-1)
            return false;
        if (board[row][col] != word[0] || ub[row][col])
            return false;

        ub[row][col] = true;

        bool res = exist(board, ub, row-1, col, word.substr(1))
                || exist(board, ub, row, col+1, word.substr(1))
                || exist(board, ub, row+1, col, word.substr(1))
                || exist(board, ub, row, col-1, word.substr(1));
        if (!res)
            ub[row][col] = false;
        return res;
    }
};
