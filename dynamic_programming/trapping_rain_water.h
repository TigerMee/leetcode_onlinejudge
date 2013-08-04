
#include "common.h"

class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (A == NULL || n <= 2) {
            return 0;
        }

        // begin[i]��i֮ǰ��һ����i�ߵ�Ԫ�ص��±�
        // ���[0,i-1]��û��Ԫ�ر�i�ߣ���ôbegin[i]��[0,i-1]����ߵ�Ԫ�ص��±�
        // ����ж��Ԫ��ͬ����ߣ���ôȡ��i�����

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
