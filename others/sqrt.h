
#include "common.h"

class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = x;
        int mid = 0;

        while (left < right) {
            mid = left + (right - left) / 2 + 1;
            if (x / mid == mid) {
                return mid;
            } else if (x / mid < mid) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }

        return right;
    }
};

class Solution2 {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double ans = x;

        while(abs(ans * ans - x) > 0.0001)
        {
            ans = (ans + x / ans) / 2;
        }

        return (int)ans;
    }
};
