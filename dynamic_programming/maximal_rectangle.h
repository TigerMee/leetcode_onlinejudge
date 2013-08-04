
#include "common.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size()));
        for (size_t i = 0; i < dp.size(); i++) {
            dp[i][0] = (matrix[i][0] == '1' ? 1 : 0);
        }
        for (size_t i = 0; i < dp.size(); i++) {
            for (size_t j = 1; j < dp[0].size(); j++) {
                dp[i][j] = (matrix[i][j] == '1' ? dp[i][j-1] + 1 : 0);
            }
        }

        int area = 0;
        for (size_t i = 0; i < dp.size(); i++) {
            for (size_t j = 0; j < dp[0].size(); j++) {
                int width = dp[i][j];
                if (width != 0) {
                    for (int k = i; k >= 0; k--) {
                        if (dp[k][j] == 0) {
                            break;
                        }
                        width = min(width, dp[k][j]);
                        area = max(area, width * (int)(i-k+1));
                    }
                }
            }
        }

        for (size_t i = 0; i < dp.size(); i++) {
            for (size_t j = 0; j < dp[i].size(); j++) {
                cout << dp[i][j] << ",";
            }
            cout << endl;
        }
        return area;
    }
};
