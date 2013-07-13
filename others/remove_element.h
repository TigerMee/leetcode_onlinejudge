
#include "common.h"

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < n; i++) {
            if (A[i] == elem) {
                if (i == n-1) {
                    n--;
                    break;
                } else {
                    int target = n-1;
                    while (i < target) {
                        if (A[target] != elem)  break;
                        target--;
                    }
                    if (i == target) {
                        n = i;
                        break;
                    }

                    int tmp = A[target];
                    A[target] = A[i];
                    A[i] = tmp;
                    n--;
                }
            }
        }
        return n;
    }
};
