
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<vector<int> > VV;
    typedef vector<int> V;

    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() < 3) {
            return VV();
        }

        VV res;
        sort(num.begin(), num.end());
        for (int i = 0; i < (int)num.size()-2; i++) {
            if (i != 0 && num[i] == num[i-1]) { // dedup
                continue;
            }

            int begin = i+1, end = num.size() - 1;
            while (begin < end) {
                int sum = num[i] + num[begin] + num[end];
                if (sum < 0) {
                    begin++;
                } else if (sum > 0) {
                    end--;
                } else if (begin != i+1 && num[begin] == num[begin-1]) { // dedup
                    begin++;
                } else if (end != num.size()-1 && num[end] == num[end+1]) {
                    end--;
                } else {
                    V v;
                    v.push_back(num[i]);
                    v.push_back(num[begin]);
                    v.push_back(num[end]);
                    res.push_back(v);
                    begin++;
                    end--;
                }
            }
        }
        return res;
    }
};
