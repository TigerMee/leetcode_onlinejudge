
#include "common.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        generator(res, "", 0, 0, n);
        return res;
    }

    /*
     * res：结果集
     * s: 当前已经生成的字符串
     * l：已经使用的"("的个数
     * r：已经使用的")"的个数
     * n："(", ")"最多的个数
     */
    void generator(vector<string> &res, string s, int l, int r, int n) {
        if (l == n) {
            res.push_back(s.append(n - r, ')'));
            return;
        }

        generator(res, s+"(", l+1, r, n);
        if (l > r) {
            generator(res, s+")", l, r+1, n);
        }
        return;
    }
};
