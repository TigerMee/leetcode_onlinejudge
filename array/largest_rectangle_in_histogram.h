
#include "common.h"

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = height.size();
        if (len == 0) {
            return 0;
        }
        stack<int> st;
        int ans = 0, curHeight, width;
        for (int i = 0; i < len; i++) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                curHeight = height[st.top()];
                st.pop();
                width = (st.empty() ? i : i - st.top() - 1);
                ans = max(ans, curHeight * width);
            }
            st.push(i);
        }
        while (!st.empty()) {
            curHeight = height[st.top()];
            st.pop();
            width = (st.empty() ? len : len - st.top() - 1);
            ans = max(ans, curHeight * width);
        }
        return ans;
    }
};

// DP
// 使用了太多的空间
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.empty()) {
            return 0;
        }

        vector<vector<int> > matrix(height.size(), vector<int>(height.size(), 0));

        // matrix[i][j] means the minimal height in [i,j].
        int area = 0;
        for (size_t j = 0; j < height.size(); j++) {
            for (size_t i = j; i < height.size(); i++) {
                if (i == j) {
                    matrix[i][j] = height[i];
                } else {
                    matrix[i][j] = min(height[i], matrix[i-1][j]);
                }

                area = max(area, (int)((i-j+1) * matrix[i][j]));
            }
        }
        return area;
    }
};
