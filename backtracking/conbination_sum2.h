
#include "common.h"



class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        typedef vector<int> V;
        typedef vector<vector<int> > VV;


        if (candidates.size() == 0 || target <= 0) {
            return VV();
        }

        VV res;

        std::sort(candidates.begin(), candidates.end());

        for (int i = 0; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i-1])  continue;

            if (candidates[i] == target) {
                V v(1, candidates[i]);
                res.push_back(v);
                break;
            }

            V c;
            for (int k = i + 1; k < candidates.size(); k++) {
                c.push_back(candidates[k]);
            }

            VV vv = combinationSum2(c, target - candidates[i]);

            for (int j = 0; j < vv.size(); j++) {
                V v(1, candidates[i]);
                for (int k = 0; k < vv[j].size(); k++) {
                    v.push_back(vv[j][k]);
                }
                res.push_back(v);
            }
        }

        return res;
    }
};
