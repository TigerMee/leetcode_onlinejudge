
#include "common.h"

class Solution {
    const int DIMENSION = 3;
    const char EMPTY = '.';

    typedef vector<vector<char> > BoardType;
    int _caculate_count;
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool is_valid = false;

        // valid row
        for (size_t i = 0; i < board.size(); i++) {
            vector<bool> filled_items(10, false);
            for (size_t j = 0; j < board[i].size(); j++) {
                if (board[i][j] != EMPTY) {
                    if (filled_items[board[i][j]-'0']) {
                        return false;
                    }
                    filled_items[board[i][j]-'0'] = true;
                }
            }
        }

        // valid column
        for (size_t j = 0; j < board[0].size(); j++) {
            vector<bool> filled_items(10, false);
            for (size_t i = 0; i < board.size(); i++) {
                if (board[i][j] != EMPTY) {
                    if (filled_items[board[i][j]-'0']) {
                        return false;
                    }
                    filled_items[board[i][j]-'0'] = true;
                }
            }
        }

        // vliad box
        for (int i = 0; i < DIMENSION; i++) {
            for (int j = 0; j < DIMENSION; j++) {
                vector<bool> filled_items(10, false);
                for (int row = i*DIMENSION; row < i*DIMENSION+DIMENSION; row++) {
                    for (int col = j*DIMENSION; col < j*DIMENSION+DIMENSION; col++) {
                        if (board[row][col] != EMPTY) {
                            if (filled_items[board[row][col]-'0']) {
                                return false;
                            }
                            filled_items[board[row][col]-'0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
