
#include "common.h"

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v = searchRange(A, 0, n-1, target);
        if (v.size() == 0) {
            v.push_back(-1);
            v.push_back(-1);
        }
        return v;
    }

    vector<int> searchRange(int A[], int start, int end, int target) {
        if (start > end)
            return vector<int>();
        if (start == end)
            return A[start] == target ? vector<int>(2, start) : vector<int>();

        int mid = start + (end-start)/2;
        vector<int> v1 = searchRange(A, start, mid, target);
        vector<int> v2 = searchRange(A, mid+1, end, target);

        if (v1.size() == 0) {
            return v2;
        } else {
            if (v2.size() == 2)
                v1[1] = v2[1];
            return v1;
        }
    }
};
