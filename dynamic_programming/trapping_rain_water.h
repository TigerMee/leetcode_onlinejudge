
#include "common.h"

class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (A == NULL || n <= 2) {
            return 0;
        }

        // begin[i]在i之前第一个比i高的元素的下标
        // 如果[0,i-1]中没有元素比i高，那么begin[i]是[0,i-1]中最高的元素的下标
        // 如果有多个元素同样最高，那么取离i最近的

        // For element i(starting from zero),
        // let us iterate each element from i-1 to 0.
        // Begin[i] is the index of the first element encountered
        // whose height is equal of greater than A[i].
        // If there is no such element, begin[i] is the index of
        // the first element encountered with the greatest height.
        vector<int> begin(n, -1);
        int max_pos = 0;

        for (int i = 1; i < n; i++) {
            int b = i-1;
            while (b >= 0) {
                if (A[i] <= A[b]) {
                    begin[i] = b;
                    break;
                }
                b = begin[b];
            }
            if (begin[i] == -1) {
                begin[i] = max_pos;
            }
            max_pos = A[i] >= A[max_pos] ? i : max_pos;
        }

        int area = 0;
        int i = n-1;
        while (i > 0) {
            int height = min(A[i], A[begin[i]]);
            for (int k = i-1; k > begin[i]; k--) {
                area += height - A[k];
            }
            i = begin[i];
        }
        return area;
    }
};
