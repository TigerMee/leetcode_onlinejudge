
#include "common.h"

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() == 0) {
            return vector<vector<int> >();
        }

        vector<vector<int> > res;

        std::sort(num.begin(), num.end());

        for (int i = 0; i < num.size(); i++) {
            if (i != 0 && num[i] == num[i-1]) {
                continue;
            }
            vector<int> conds;
            for (int j = 0; j < num.size(); j++) {
                if (j != i) conds.push_back(num[j]);
            }


            vector<vector<int> > vv = permuteUnique(conds);
            if (vv.size() == 0) {
                vector<int> v(1, num[i]);
                res.push_back(v);
            } else {
                for (int j = 0; j < vv.size(); j++) {
                    vector<int> v = vv[j];
                    v.push_back(num[i]);
                    res.push_back(v);
                }
            }
        }

        return res;
    }
};
