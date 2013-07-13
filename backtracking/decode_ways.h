
#include "common.h"

class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() == 0)
            return 0;

        int r1 = 0;
        int r2 = 0;

        if (s[0] < '1' || s[0] > '9')
            return 0;
        r1 = 1;

        for (size_t i = 1; i < s.length(); i++) {
            char cur = s[i];
            char pre = s[i-1];
            int last_r1 = r1;

            if (cur == '0')
                r1 = 0;
            else
                r1 += r2;

            if (pre == '1' || (pre == '2' && cur <= '6'))
                r2 = last_r1;
            else
                r2 = 0;
        }

        return r1+r2;
    }
};
