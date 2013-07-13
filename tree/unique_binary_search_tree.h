
#include "common.h"

class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return num(1, n);
    }

    int num(int begin, int end) {
        if (begin <= 0 || end < begin) return 1;    // ¿ÕÊ÷

        int res = 0;
        for (int i = begin; i <= end; i++) {
            int left = num(begin, i-1);
            int right = num(i+1, end);
            res += left * right;
        }
        return res;
    }
};
