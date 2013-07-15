
#include "common.h"

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return n;

        int next = 1;   // position to write next valid value.
        bool need_remove = false;

        for (int i = 1; i < n; i++) {
            if (A[i] == A[next-1]) {
                if (!need_remove) {
                    A[next] = A[i];
                    next++;
                    need_remove = true;
                }s
            } else {
                A[next] = A[i];
                next++;
                need_remove = false;
            }
        }
        return next;
    }
};
