
#include "common.h"

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<vector<int> > res;
        if (num.size() == 0) {
            return vector<vector<int> >();
        }

        res.push(vector<int>(1, num[0]));
        for (int i = 1; i < num.size(); i++) {
            int last_item_size = res.front().size();
            int cur_item_size = 0;

            printf("number[%d]\n", num[i]);

            while ((cur_item_size = res.front().size()) == last_item_size) {
                const vector<int> &cur_v = res.front();
                for (int item_idx = 0; item_idx <= cur_v.size(); item_idx++) {
                    vector<int> v;
                    for (int k = 0; k < item_idx; k++) {
                        v.push_back(cur_v[k]);
                    }
                    v.push_back(num[i]);
                    for (int k = item_idx; k < cur_v.size(); k++) {
                        v.push_back(cur_v[k]);
                    }
                    res.push(v);
                }
                res.pop();
            }
        }

        vector<vector<int> > res_v;

        while(!res.empty()) {
            res_v.push_back(res.front());
            res.pop();
        }
        return res_v;
    }
};
