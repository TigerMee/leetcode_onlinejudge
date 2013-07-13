

#include "common.h"

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int H_LEN = strlen(haystack);
        const int N_LEN = strlen(needle);

        if (N_LEN == 0) return haystack;
        if (H_LEN < N_LEN) return NULL;

        int *table = new int[N_LEN];
        build_partial_match_table(needle, table, N_LEN);

        int hidx = 0;
        int nidx = 0;
        while (hidx + nidx < H_LEN) {
            cout << "hidx=" << hidx << ", nidx=" << nidx << endl;
            if (haystack[hidx+nidx] == needle[nidx]) {
                if (nidx == N_LEN-1) return haystack + hidx;
                nidx++;
            } else {
                // table[0]必须是-1
                // 如果hidx=0，nidx=0，如果table[0]不是-1，则会陷入死循环
                hidx = hidx + nidx - table[nidx];
                if (table[nidx] > -1) nidx = table[nidx];
                else nidx = 0;
            }
        }
        return NULL;
    }

    void build_partial_match_table(const char *str, int *table, size_t len) {
        if (len <= 0) return;
        table[0] = -1;
        if (len == 1) return;
        table[1] = 0;

        size_t pos = 2;
        size_t cnd = 0;    // next character of the current candidate substring

        while (pos < len) {
            if (str[pos-1] == str[cnd]) {
                cnd++;
                table[pos] = cnd;
                pos++;
            } else if (cnd > 0) {
                cnd = table[cnd];
            } else {
                table[pos] = 0;
                pos++;
            }
        }
        return;
    }
};

