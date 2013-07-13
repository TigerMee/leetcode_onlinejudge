
#include "common.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        if (digits.length() == 0) {
            res.push_back("");
            return res;
        }

        string mapping[] = {
            " ",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        queue<string> q;
        for (int i = 0; i < digits.length(); i++) {
            int dig = digits[i] - '1' + 1;
            if (dig == 1) {
                continue;
            }

            if (q.empty()) {
                for (int j = 0; j < mapping[dig].length(); j++) {
                    string s;
                    s.append(1, mapping[dig][j]);
                    q.push(s);
                }
            } else {
                int old_str_len = q.front().length();

                while (q.front().length() == old_str_len) {
                    for (int j = 0; j < mapping[dig].length(); j++) {
                        string s = q.front();
                        s.append(1, mapping[dig][j]);
                        q.push(s);
                    }
                    q.pop();
                }
            }
        }

        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
