
#include "common.h"

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        map<string, vector<string> > dict;

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            dict[str].push_back(strs[i]);
        }

        for (map<string, vector<string> >::const_iterator it = dict.begin();
            it != dict.end(); ++it) {
            if (it->second.size() > 1) {
                res.insert(res.end(), it->second.begin(), it->second.end());
            }
        }
        return res;
    }
};
