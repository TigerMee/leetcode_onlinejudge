
#include "common.h"

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return find(A, m, 0, m-1, B, n, 0, n-1, (m+n)/2.0);
    }

    double find(int A[], int m, int astart, int aend,
                int B[], int n, int bstart, int bend,
                double mid) {
        printf("A[%d, %d], B[%d, %d], mid=%f\n",
                astart, aend, bstart, bend, mid);

        if (astart < 0 || aend >= m || astart > aend)
            return B[(int)mid-1+bstart];
        if (bstart < 0 || bend >= n || bstart > bend)
            return A[(int)mid-1+astart];
        if (mid == 0 || mid==1) {
            return min(A[astart], B[bstart]);
        }
        if (astart == aend || bstart == bend) {
            int *p1 = astart == aend ? A : B;
            int *p2 = p1 == A ? B : A;
            int s1 = p1 == A ? astart : bstart;
            int s2 = p2 == A ? astart : bstart;

            if (p1[s1] > p2[s2+(int)mid])
                return p2[s2+(int)mid-1];
            if (p1[s1] > p2[s2+(int)mid-1])
                return p1[s1];
            else
                return p2[s2+(int)mid-2];
        }

        int ma = (int)ceil((aend-astart)/2.0) + astart;   // ceil as mid index
        int mb = (int)ceil((bend-bstart)/2.0) + bstart;

        if (A[ma] == B[mb]) {
            if (abs((ma-astart)+(mb-bstart) - (int)mid) <= 2)
                return A[ma];
            else
                return find(A, m, ma+1, aend, B, n, mb+1, bend, mid-(ma-astart+1)-(mb-bstart+1));
        } else if (A[ma] < B[mb]) {
            return find(A, m, ma, aend, B, n, bstart, mb-1, mid-(ma-astart));
        } else {
            return find(A, m, astart, ma-1, B, n, mb, bend, mid-(mb-bstart));
        }
    }
};
