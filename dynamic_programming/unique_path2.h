
#include "common.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > matrix(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            matrix[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
             if (obstacleGrid[0][j] == 1) {
                 break;
             }
             matrix[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] = (obstacleGrid[i][j] == 1 ?
                                0 : matrix[i-1][j] + matrix[i][j-1]);
            }
        }

        return matrix[m-1][n-1];
    }
};
