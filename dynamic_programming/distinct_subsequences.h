
#include "common.h"

class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (T.length() == 0 || S.length() < T.length())
            return 0;

        vector<vector<int> > res;
        res.reserve(S.length());
        for (size_t i = 0; i < S.length(); i++) {
            res.push_back(vector<int>());
            res[i].reserve(T.length());

            if (i == 0)
                res[i][0] = S[0] == T[0] ? 1 : 0;
            else
                res[i][0] = S[i] == T[0] ? res[i-1][0] + 1 : res[i-1][0];
        }

        for (size_t i = 0; i < S.length(); i++) {
            for (size_t j = 1; j < T.length(); j++) {
                if (S[i] == T[j])
                    res[i][j] = i > 0 ? res[i-1][j-1] + res[i-1][j] : 0;
                else
                    res[i][j] = i > 0 ? res[i-1][j] : 0;
            }
        }

        return res[S.length()-1][T.length()-1];
    }
};
