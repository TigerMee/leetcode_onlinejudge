
// 每一步选取可能性最小的方格（非严格）
//
class Solution2 {
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
        get_next_square(board, row, col, possible_values);

        for (set<char>::iterator it = possible_values.begin(); it != possible_values.end(); ++it) {
            board[row][col] = *it;
            if (solve(board, step+1)) return true;
            board[row][col] = EMPTY;
        }

        return false;
    }

    void get_next_square(vector<vector<char> > &board, int &row, int &col, set<char> &possible_values) {
        // constrains
        // 1. the square with least candidates (local count)
        // 2. look ahead
        _caculate_count++;
        int local_count = INT_MAX;    // number of candidates

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                if (board[r][c] != EMPTY) {
                    continue;
                }

                // 1. get possible values
                set<char> possible;
                for (int k = 1; k < 10; k++) {
                    possible.insert('0'+k);
                }
                // iterate row
                vector<char> &cur_row = board[r];
                for (int k = 0; k < cur_row.size(); k++) {
                    if (cur_row[k] != EMPTY) {
                        possible.erase(cur_row[k]);
                    }
                }
                // iterate column
                for (BoardType::iterator rit = board.begin(); rit != board.end(); ++rit) {
                    if ((*rit)[c] != EMPTY) {
                        possible.erase((*rit)[c]);
                    }
                }
                // iterate current sub-box
                int start_r = r/3 * 3;
                int start_c = c/3 * 3;
                for (int rr = start_r; rr < start_r + DIMENSION; rr++) {
                    for (int cc = start_c; cc < start_c + DIMENSION; cc++) {
                        if (board[rr][cc] != EMPTY) {
                            possible.erase(board[rr][cc]);
                        }
                    }
                }

                // 2. constrains
                if (possible.size() < local_count) {
                    row = r;
                    col = c;
                    possible_values = possible;
                    if (possible_values.size() == 0) {
                        return;
                    }
                }
            }
        }
        return;
    }
};

// 暴力法
class Solution3 {
    int _caculate_count;
public:
    bool isValid(vector<vector<char> > &board, int x, int y)
	{
	    _caculate_count++;
		int i, j;
		for (i = 0; i < 9; i++)
			if (i != x && board[i][y] == board[x][y])
				return false;
		for (j = 0; j < 9; j++)
			if (j != y && board[x][j] == board[x][y])
				return false;
		for (i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)
			for (j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)
				if (i != x && j != y && board[i][j] == board[x][y])
					return false;
		return true;
	}
	bool solve(vector<vector<char> > &board)
	{
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
			{
				if ('.' == board[i][j])
				{
					for (int k = 1; k <= 9; ++k)
					{
						board[i][j] = '0' + k;
						if (isValid(board, i, j) && solve(board))
							return true;
						board[i][j] = '.';
					}
					return false;
				}
			}
		return true;
	}
	bool solveSudoku(vector<vector<char> > &board) {
	    _caculate_count = 0;
	    solve(board);
	    cout << _caculate_count << endl;
	}
};
