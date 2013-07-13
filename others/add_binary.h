
#include "common.h"

class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max_len = max(a.length(), b.length());
        if (max_len == 0) {
            return string();
        }

        string res(max_len + 1, '0');
        bool carry = false;
        char c_a = 0, c_b = 0;

        for (size_t i = 0; i < res.length(); i++) {
            int r_idx = res.length() - 1 - i;
            int a_idx = a.length() - 1 - i;
            int b_idx = b.length() - 1 - i;

            c_a = a_idx < 0 ? '0' : a[a_idx];
            c_b = b_idx < 0 ? '0' : b[b_idx];

            if (c_a == c_b) {
                res[r_idx] = carry ? '1' : '0';
                carry = c_a == '1';
            } else {
                res[r_idx] = carry ? '0' : '1';
            }
        }
        if (res[0] == '0') {
            res = res.substr(1);
        }
        return res;
    }
};
