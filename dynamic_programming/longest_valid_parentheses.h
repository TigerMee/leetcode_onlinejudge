
#include "common.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() <= 1) return 0;

        int len = 0;
        vector<int> valid(1, -1);

        for (size_t i = 1; i < s.length(); i++) {
            if (s[i] == '(') {
                valid.push_back(-1);
            } else {
                valid.push_back(-1);
                if (s[i-1] == '(') {
                    valid[i] = i-1;
                } else {
                    while (true) {
                        int begin = i-1;
                        while (begin >= 0) {
                            if (valid[begin] == -1) break;
                            begin = valid[begin]-1;
                        }
                        if (begin >= 0 && s[begin] == '(') valid[i] = begin;
                        break;
                    }
                }
                // refresh i;
                int begin = valid[i]-1;
                while (begin >= 0) {
                    if (valid[begin] != -1) {
                        valid[i] = valid[begin];
                        begin = valid[begin]-1;
                    } else {
                        break;
                    }
                }
                len = max(len, int(valid[i] != -1 ? i-valid[i]+1 : 0));
            }
        }
        print_v(valid);
        return len;
    }
};
