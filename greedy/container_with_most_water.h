
#include "common.h"

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.size() == 0) {
            return 0;
        }

        int max_area = INT_MIN;

        int begin = 0, end = height.size() - 1;
        while (begin < end) {
            int cur = (end - begin) * min(height[begin], height[end]);
            max_area = max(max_area, cur);
            if (height[begin] < height[end]) {
                begin++;
            } else {
                end--;
            }
        }
        return max_area;
    }
};
