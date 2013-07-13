
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() == 0) {
            return 0;
        }

        int last_pos[128];
        for (int i = 0; i < 128; i++)
            last_pos[i] = -1;

        int llen = 1;
        int begin = 0;

        for (int i = 0; i < s.length(); i++) {
            if (last_pos[s[i]] >= begin)
                begin = last_pos[s[i]] + 1;

            int cur_len = i - begin + 1;
            if (cur_len > llen) {
                llen = cur_len;
            }
            last_pos[s[i]] = i;
        }

        return llen;
    }
};


class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() == 0) {
            return 0;
        }

        int llen = 1;
        int begin = 0;

        for (int i = 1; i < s.length(); i++) {
            for (int k = i - 1; k >= begin; k--) {
                if (s[k] == s[i]) {
                    begin = k + 1;
                    break;
                }
            }

            int cur_len = i - begin + 1;
            if (cur_len > llen) {
                llen = cur_len;
            }
        }

        return llen;
    }
};
