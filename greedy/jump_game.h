
#include "common.h"

class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0)
            return true;

        int step = A[0];

        for (int i = 1; i < n; i++) {
            if (step > 0) {
                step--;
                step = max(step, A[i]);
            } else
                return false;
        }

        return true;
    }
};
