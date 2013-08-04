
#include "common.h"

class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1) {
            return string();
        }

        string res("1");
        for (int i = 1; i < n; i++) {
            string tmp = res;
            res.clear();

            int count = 1;
            char c = tmp[0];

            for (size_t j = 1; j < tmp.length(); j++) {
                if (tmp[j] != c) {
                    res.push_back('0' + count);
                    res.push_back(c);

                    count = 1;
                    c = tmp[j];
                    continue;
                }
                count++;
            }
            res.push_back('0' + count);
            res.push_back(c);
        }

        return res;
    }
};
