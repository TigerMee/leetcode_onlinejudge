
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() == 0) {
            return 0;
        }

        bool is_pal[s.length()][s.length()];
        for (int i = 0; i < s.length(); i++) {
            is_pal[i][i] = true;
        }

        int max_len = 1;
        int begin = 0, end = 0;

        for (int i = 1; i < s.length(); i++) {
            int mlen = 0;
            int cbegin = i, cend = i;

            for (int k = 0; k <= i; k++) {
                is_pal[k][i] = (i == k)
                                || ((k + 1 == i) && s[k] == s[i])
                                || (is_pal[k + 1][i - 1] && s[k] == s[i]);
                if (is_pal[k][i]) {
                    int cur_len = i - k + 1;
                    if (mlen < cur_len) {
                        mlen = cur_len;
                        cbegin = k;
                        cend = i;
                    }
                }
            }
            if (mlen > max_len) {
                max_len = mlen;
                begin = cbegin;
                end = cend;
            }
        }

        return string(s, begin, (end - begin + 1));
    }
};
