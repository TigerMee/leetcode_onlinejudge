
#include "common.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.size() == 0 && matrix[0].size() == 0) {
            return false;
        }

        int row = matrix.size() - 1;

        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == target) {
                return true;
            } else if (matrix[i][0] > target) {
                row = i - 1;
                break;
            }
        }
        if (row < 0) {
            return false;
        }

        int begin = 0;
        int end = matrix[row].size() - 1;
        while (begin <= end) {
            int mid = begin + (end - begin) / 2;
            int cur = matrix[row][mid];

            if (cur == target) {
                return true;
            } else if (cur < target) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }
};
