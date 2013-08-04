
#include "common.h"

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (board.empty()) {
            return;
        }

        //top, bottom, left, right
        for (size_t j = 0; j < board[0].size(); j++) {
            changeUnsurroundedO(board, 0, j);
            changeUnsurroundedO(board, board.size()-1, j);
        }
        for (size_t i = 0; i < board.size(); i++) {
            changeUnsurroundedO(board, i, 0);
            changeUnsurroundedO(board, i, board[0].size()-1);
        }

        // change 'O' to 'X'
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        // change '#' to "O'
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void changeUnsurroundedO(vector<vector<char> > &board, size_t i, size_t j) {
        if (i >= board.size() || j >= board[0].size()) {
            return;
        }

        if (board[i][j] == 'O') {
            board[i][j] = '#';

            changeUnsurroundedO(board, i-1, j);
            changeUnsurroundedO(board, i+1, j);
            changeUnsurroundedO(board, i, j-1);
            changeUnsurroundedO(board, i, j+1);
        }
    }
};
