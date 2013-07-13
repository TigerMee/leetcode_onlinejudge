
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;

        if (num.size() < 4) {
            return res;
        }

        sort(num.begin(), num.end());

        for (int i = 0; i < num.size(); i++) {
            vector<vector<int> > threev;
            threeSum(num, i + 1, target - num[i], threev);

            cout << "threev::size: " << threev.size() << endl;
            // check duplicate
            for (int k = 0; k < threev.size(); k++) {
                bool isExists = false;
                for (int h = 0; h < res.size(); h++) {
                    if (res[h][0] == num[i]
                    && res[h][1] == threev[k][0]
                    && res[h][2] == threev[k][1]
                    && res[h][3] == threev[k][2]) {
                        isExists = true;
                        break;
                    }
                }
                if (!isExists) {
                    vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(threev[k][0]);
                    v.push_back(threev[k][1]);
                    v.push_back(threev[k][2]);
                    res.push_back(v);
                }
            }
        }

        return res;
    }

    void threeSum(vector<int> &num, int start_pos, int target, vector<vector<int> > &res) {
        if (num.size() - start_pos < 3) {
            return;
        }

        cout << "num::size: " << num.size()
            << ", start_pos: " << start_pos
            << ", target: " << target << endl;

        for (int i = start_pos; i < num.size(); i++) {
            int begin = i + 1;
            int end = num.size() - 1;

            while (begin < end) {
                int val = num[i] + num[begin] + num[end];
                if (val == target) {
                    bool isExists = false;
                    for(vector<vector<int> >::iterator it = res.begin(); it != res.end(); ++it) {
                        if ((*it)[0] == num[i]
                            && (*it)[1] == num[begin]
                            && (*it)[2] == num[end]) {
                            isExists = true;
                            break;
                        }
                    }
                    cout << "num: " << num[i] << "," << num[begin] << "," << num[end]
                    << ", val: " << val
                    << ", exists: " << isExists
                    << endl;
                    if (!isExists) {
                        vector<int> v;
                        v.push_back(num[i]);
                        v.push_back(num[begin]);
                        v.push_back(num[end]);
                        res.push_back(v);
                    }
                    begin++;
                    end--;
                } else if (val < target) {
                    begin++;
                } else {
                    end--;
                }
            }
        }
        return;
    }
};
