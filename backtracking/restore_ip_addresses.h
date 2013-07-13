
#include "common.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return restore(s, 4);
    }

    vector<string> restore(string s, int n) {
        vector<string> res;
        if (s.length() == 0 || n <= 0 || s.length() < n) return res;

        if (n == 1) {
            if (valid_int(s)) res.push_back(s);
            return res;
        }

        for (size_t i = 1; i < s.length(); i++) {
            string cur = s.substr(0, i);
            if (!valid_int(cur)) break;

            vector<string> v = restore(s.substr(i), n-1);
            for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
                string ss = cur + "." + *it;
                res.push_back(ss);
            }
        }
        return res;
    }

    bool valid_int(const string &s) {
        return !(atoi(s.c_str()) > 255
                || (s.length() > 1 && s[0] == '0'));
    }
};
