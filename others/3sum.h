
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT w1rite int main() function
        vector<vector<int> > res;

        if (num.size() < 3) {
            return res;
        }

        sort(num.begin(), num.end());

        for (int i = 0; i < num.size(); i++) {
            int begin = i + 1;
            int end = num.size() - 1;

            while (begin < end) {
                int val = num[i] + num[begin] + num[end];
                if (val == 0) {
                    bool isExists = false;
                    for(vector<vector<int> >::iterator it = res.begin(); it != res.end(); ++it) {
                        if ((*it)[0] == num[i]
                            && (*it)[1] == num[begin]
                            && (*it)[2] == num[end]) {
                            isExists = true;
                            break;
                        }
                    }
                    if (!isExists) {
                        vector<int> v;
                        v.push_back(num[i]);
                        v.push_back(num[begin]);
                        v.push_back(num[end]);
                        res.push_back(v);
                    }
                    begin++;
                    end--;
                } else if (val < 0) {
                    begin++;
                } else {
                    end--;
                }
            }
        }
        return res;
    }
};
