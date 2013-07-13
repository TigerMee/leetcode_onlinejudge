
#include "common.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        if (s3.length() == 0) {
            return true;
        }

        bool res = false;
        if (s1.length() > 0
            && s1[s1.length()-1] == s3[s3.length()-1]) {
            res = isInterleave(string(s1, 0, s1.length()-1),
                                s2,
                                string(s3, 0, s3.length()-1));
        }
        if (!res
            && s2.length() > 0
            && s2[s2.length()-1] == s3[s3.length()-1]) {
            res = isInterleave(s1,
                                string(s2, 0, s2.length()-1),
                                string(s3, 0, s3.length()-1));
        }

        return res;
    }
};
