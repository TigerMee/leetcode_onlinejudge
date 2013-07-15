
#include "common.h"

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int begin = 0, end = 0;
        while (i < n-1) {
            if (A[i] == A[i+1]) {
                begin = i+1;
                end = begin;
                while (end < n-1 && A[end] == A[end+1])
                    end++;
                n = remove(A, n, begin, end);
            }
            i++;
        }
        if (n > 1 && A[n-1] == A[n-2])
            n--;
        return n;
    }

    int remove(int A[], int n, int begin, int end) {
        memcpy(A+begin, A+end+1, (n-(end+1)) * sizeof(int));
        return n - (end-begin+1);
    }
};
