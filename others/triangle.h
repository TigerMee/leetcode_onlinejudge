
#include "common.h"

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (triangle.size() == 0) {
            return 0;
        }

        vector<int> res(triangle[triangle.size() - 1].size());

        res[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = triangle[i].size() - 1; j >= 0; j--) {
                if (j == triangle[i].size() - 1) {
                    res[j] = res[j - 1] + triangle[i][j];
                } else if (j == 0) {
                    res[j] = res[j] + triangle[i][j];
                } else {
                    res[j] = min(res[j - 1], res[j]) + triangle[i][j];
                }
            }
        }

        int r = res[0];
        for (int i = 1; i < res.size(); i++) {
            r = min(r, res[i]);
        }
        return r;
    }
};

/*
// recurtion
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return minSum(triangle, 0, 0);
    }

    int minSum(vector<vector<int> > &triangle, int level, int idx) {
        if (level > triangle.size() - 1
        || idx > triangle[level].size() - 1) {
            return 0;
        }

        int min_left = minSum(triangle, level + 1, idx);
        int min_right = minSum(triangle, level + 1, idx + 1);

        printf("level[%d], node[%d], left[%d], right[%d]\n",
               level, triangle[level][idx], min_left, min_right);

        return triangle[level][idx]
                + (min_left > min_right ? min_right : min_left);
    }
};
*/
