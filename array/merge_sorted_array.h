
#include "common.h"

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return;
        if (m == 0) {
            memcpy(A, B, sizeof(int)*n);
            return;
        }

        int a = m-1;
        int b = n-1;
        int cur = m+n-1;

        while (cur >= 0) {
            if (b < 0) break;
            if (a < 0) {
                memcpy(A, B, sizeof(int)*(b+1));
                return;
            }
            if (A[a] >= B[b]) {
                A[cur] = A[a];
                a--;
            } else {
                A[cur] = B[b];
                b--;
            }
            cur--;
        }
        return;
    }
};
