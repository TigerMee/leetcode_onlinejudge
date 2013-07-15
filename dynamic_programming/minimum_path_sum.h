
#include "common.h"

class Solution {
public:
    int minPathSum(const vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // return minPathSum(grid, 0, 0);
        if (grid.size() == 0) {
            return 0;
        }

        vector<vector<int> > val;
        for (int row = 0; row < grid.size(); row++) {
            vector<int> v;
            for (int col = 0; col < grid[0].size(); col++) {
                int cur = grid[row][col];
                if (row == 0 && col == 0)
                    cur = cur;
                else if (row == 0)
                    cur = v[col-1] + cur;
                else if (col == 0)
                    cur = val[row-1][col] + cur;
                else {
                    cur = min(v[col-1], val[row-1][col]) + cur;
                }

                v.push_back(cur);
            }
            val.push_back(v);
        }

        return val[val.size()-1][val[0].size()-1];

    }
};
