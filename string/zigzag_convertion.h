
#include "common.h"

class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() == 0 || nRows <= 1)
            return s;

        bool reverse = false;
        vector<string> res(nRows, string());

        int row = 0;
        int idx = 0;
        while (idx < s.length()) {
            res[row] += s[idx];

            if (reverse) {
                row--;
                if (row < 1) {
                    row = 0;
                    reverse = !reverse;
                }
            } else {
                row++;
                if (row > nRows-1) {
                    if (nRows == 2) {
                        row = 0;
                    } else {
                        row = nRows-2;
                        reverse = !reverse;
                    }
                }
            }

            idx++;
        }

        string str;
        for (size_t i = 0; i < res.size(); i++) {
            str += res[i];
        }

        return str;
    }
};
