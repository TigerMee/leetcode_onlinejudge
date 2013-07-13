
#include "common.h"

// 基本思路
// divisor每次乘2
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int64_t dd = dividend;
        int64_t dr = divisor;

        printf("%d/%d\n", dd, dr);
        bool minus = false;
        if (dd < 0) {
            minus = !minus;
            dd = abs(dd);
        }
        if (dr < 0) {
            minus = !minus;
            dr = abs(dr);
        }

        if (dd < dr || dr == 0) {
            return 0;
        } else if (dd == dr) {
            return minus ? -1 : 1;
        }

        uint64_t res = 1;
        uint64_t cur = dr;

        while (cur <= dd) {
            printf("cur: %llu\n", cur);
            cur <<= 1; // *2
            res <<= 1;
        }

        if (cur > dd) {
            cur >>= 1;
            res >>= 1;

            res += divide(dd - (int)cur, dr);
        }

        return minus ? -res : res;
    }
};
