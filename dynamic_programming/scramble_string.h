
#include "common.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.length() != s2.length()) {
            return false;
        }
        if (s1.length() == 0) {
            return true;
        }

        const size_t LEN = s1.length();
        // matrix: [s1][s2][length]
        // length start from 1 and end with LEN
        vector<vector<vector<bool> > > matrix(
            LEN, vector<vector<bool> >(
                LEN, vector<bool>(LEN + 1, false)));

        for (size_t i = 0; i < LEN; i++) {
            for (size_t j = 0; j < LEN; j++) {
                matrix[i][j][1] = (s1[i] == s2[j]);
            }
        }

        for (size_t len = 2; len <= LEN; len++) {
            for (size_t i = 0; i <= LEN-len; i++) {
                for (size_t j = 0; j <= LEN-len; j++) {
                    for (size_t sublen = 1; sublen < len; sublen++) {
                        if ((matrix[i][j][sublen] && matrix[i+sublen][j+sublen][len-sublen])
                            || (matrix[i][j+(len-sublen)][sublen] && matrix[i+sublen][j][len-sublen])) {
                            matrix[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }

        return matrix[0][0][LEN];
    }
};
