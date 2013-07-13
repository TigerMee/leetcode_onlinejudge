
#include "common.h"

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string prefix;
        if (strs.size() == 0) {
            return prefix;
        }

        prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string new_prefix;

            for (int j = 0;
                j < strs[i].size() && j < prefix.size();
                j++) {
                if (strs[i][j] == prefix[j]) {
                    new_prefix.append(1, prefix[j]);
                } else {
                    break;
                }
            }
            prefix = new_prefix;
        }

        return prefix;
    }
};
