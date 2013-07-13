
#include "common.h"
class Solution {
    typedef vector<vector<int> > VV;
    typedef vector<int> V;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (S.empty()) {
            return VV();
        }

        int cur = S.back();
        S.pop_back();

        VV vv = subsets(S);
        VV res;
        if (vv.size() == 0) {
            V v;
            res.push_back(v);

            v.push_back(cur);
            res.push_back(v);
        } else {
            res = vv;
            for (size_t i = 0; i < vv.size(); i++) {
                vv[i].push_back(cur);
                sort(vv[i].begin(), vv[i].end());
                res.push_back(vv[i]);
            }
        }

        return res;
    }
};
