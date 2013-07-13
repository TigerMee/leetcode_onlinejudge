
#include "common.h"

class Solution {
public:
    typedef vector<vector<int> > VV;

    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return combine(1, n, k);
    }

    VV combine(int start, int end, int k) {
        if (k <= 0 || end - start + 1 < k)
            return VV();

        VV res;
        if (k-1 > 0) {
            VV inc = combine(start+1, end, k-1);
            for (size_t i = 0; i < inc.size(); i++) {
                inc[i].insert(inc[i].begin(), start);
                res.push_back(inc[i]);
            }
        } else {
            vector<int> v(1, start);
            res.push_back(v);
        }

        VV exc = combine(start+1, end, k);
        for (size_t i = 0; i < exc.size(); i++) {
            res.push_back(exc[i]);
        }

        return res;
    }

};
