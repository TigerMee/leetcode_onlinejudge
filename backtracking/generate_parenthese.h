
#include "common.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        generator(res, "", 0, 0, n);
        return res;
    }

    void generator(vector<string> &res, string s, int l, int r, int n) {
        if (l == n) {
            res.push_back(s.append(n - r, ')'));
            return;
        }

        generator(res, s+"(", l+1, r, n);
        if (l > r) {
            generator(res, s+")", l, r+1, n);
        }
        return;
    }
};
