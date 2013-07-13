
#include "common.h"

class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1)
            return 0;

        int steps = 0;
        int begin = 0;
        int end = A[0];

        while (end < n-1) {
            int target = 0;
            int target_end = 0;

            for (int i = begin; i <= end; i++) {
                if (i+A[i] > target_end) {
                    target = i;
                    target_end = i+A[i];
                }
            }
            if (target == target_end)
                break;
            begin = target;
            end = target_end;
            steps++;
        }
        steps++;

        return steps;

    }
};
