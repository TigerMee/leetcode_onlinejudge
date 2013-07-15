
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < n; i++) {
            if (A[i] >= target)
                return i;
        }
        return n;
    }
};
