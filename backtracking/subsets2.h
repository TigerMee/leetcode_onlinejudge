
#include "common.h"

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::sort(S.begin(), S.end());
        return subsetsWithDup(S, 0);
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S, size_t start) {
        if (start >= S.size()) {
            return vector<vector<int> >(1, vector<int>());
        }

        vector<int> cur(1, S[start]);
        start++;

        // subsets without current
        vector<vector<int> > exc_v = subsetsWithDup(S, start);

        // subsets with current
        while (start < S.size()) {
            if (S[start] != S[start-1]) {
                break;
            }
            start++;
            cur.push_back(cur[0]);
        }

        vector<vector<int> > inc_v = subsetsWithDup(S, start);

        if (inc_v.empty()) {
            inc_v.push_back(cur);
        } else {
            for (size_t i = 0; i < inc_v.size(); i++) {
                inc_v[i].insert(inc_v[i].begin(), cur.begin(), cur.end());
            }
        }
        inc_v.insert(inc_v.end(), exc_v.begin(), exc_v.end());
        return inc_v;
    }
};
