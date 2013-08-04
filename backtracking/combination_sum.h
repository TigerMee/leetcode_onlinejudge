
#include "common.h"

class Solution {
public:
    typedef vector<vector<int> > VV;
    typedef vector<int> V;

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end());
        return combinationSum(candidates, 0, target);
    }

    VV combinationSum(V &candidates, int begin, int target) {
        if (candidates.size() == 0
            || begin < 0 || begin > candidates.size()-1
            || target <= 0 || target < candidates[begin]) {
            return VV();
        }

        VV res;
        for (int i = begin; i < candidates.size(); i++) {
            if (target == candidates[i]) {
                res.push_back(V(1, target));
            } else {
                VV tmp = combinationSum(candidates, i, target-candidates[i]);
                for (VV::iterator it = tmp.begin(); it != tmp.end(); ++it) {
                    it->insert(it->begin(), candidates[i]);
                    res.push_back(*it);
                }
            }
        }
        return res;
    }
};
