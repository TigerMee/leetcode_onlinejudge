
#include "common.h"

class Solution {
    const int DIMENSION = 3;
    const char EMPTY = '.';

    typedef vector<vector<char> > BoardType;
    int _caculate_count;
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int step = 0;
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                if (board[r][c] != EMPTY) step++;
            }
        }
        _caculate_count = 0;
        cout << solve(board, step) << endl;
        cout << _caculate_count << endl;
    }

    bool solve(vector<vector<char> > &board, int step) {
        // 1. is_a_solution
        if (step == DIMENSION*DIMENSION*9) {
            return true;
        }

        // 2. get candidates
        int row = 0, col = 0;   // position to move next, start from 0;
        set<char> possible_values;
        get_next_square(board, row, col, possible_values, step);

        for (set<char>::iterator it = possible_values.begin(); it != possible_values.end(); ++it) {
            board[row][col] = *it;
            if (solve(board, step+1)) return true;
            board[row][col] = EMPTY;
        }

        return false;
    }

    void get_next_square(vector<vector<char> > &board, int &row, int &col, set<char> &possible_values, int step) {
        // constrains
        // 1. the square with least candidates (local count)
        // 2. look ahead
        _caculate_count++;
        int local_count = INT_MAX;    // number of candidates

        // 1.找到已填充方格最多的box
        int rq = -1, cq = -1;
        int n_box_item = -1;
        for (int i = 0; i < DIMENSION; i++) {
            for (int j = 0; j < DIMENSION; j++) {
                int cur_n_item = 0;
                for (int ii = i*DIMENSION; ii < i*DIMENSION+DIMENSION; ii++) {
                    for (int jj = j*DIMENSION; jj < j*DIMENSION+DIMENSION; jj++) {
                        if (board[ii][jj] != EMPTY) {
                            cur_n_item++;
                        }
                    }
                }
                if (cur_n_item < DIMENSION*DIMENSION && cur_n_item > n_box_item) {
                    rq = i;
                    cq = j;
                    n_box_item = cur_n_item;
                }
            }
        }
        if (rq == -1||cq==-1) {
            print_board(board);
        }
        // 2.从这个方格中随机找到一个未填充的square
        bool b_find = false;
        for (int i = rq*DIMENSION; i < rq*DIMENSION+DIMENSION; i++) {
            for (int j = cq*DIMENSION; j < cq*DIMENSION+DIMENSION; j++) {
                if (board[i][j] == EMPTY) {
                    row = i;
                    col = j;
                    b_find = true;
                    break;
                }
            }
            if (b_find) break;
        }

        // 3. get possible values
        vector<bool> possible(DIMENSION*DIMENSION+1, true);
        // iterate row
        for (int k = 0; k < board[row].size(); k++) {
            if (board[row][k] != EMPTY) {
                possible[board[row][k]-'0'] = false;
            }
        }
        // iterate column
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] != EMPTY) {
                possible[board[i][col]-'0'] = false;
            }
        }
        // iterate current sub-box
        int start_r = row/3 * 3;
        int start_c = col/3 * 3;
        for (int rr = start_r; rr < start_r + DIMENSION; rr++) {
            for (int cc = start_c; cc < start_c + DIMENSION; cc++) {
                if (board[rr][cc] != EMPTY) {
                    possible[board[rr][cc]-'0'] = false;
                }
            }
        }

        possible_values.clear();
        for (int i = 1; i < possible.size(); i++) {
            if (possible[i]) {
                possible_values.insert('0'+i);
            }
        }
        return;
    }

    void print_board(vector<vector<char> > &board) {
        printf("------board------\n");
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

