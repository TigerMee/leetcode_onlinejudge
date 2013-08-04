
#include "common.h"

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() < 3) {
            return 0;
        }

        int ret = num[0] + num[1] + num[2];
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size()-2; i++) {
            int begin = i+1, end = num.size()-1;
            while (begin < end) {
                int sum = num[i] + num[begin] + num[end];
                if (abs(target - ret) >= abs(target - sum)) {
                    ret = sum;
                    if (ret == target) {
                        return ret;
                    }
                }

                if (sum < target) {
                    begin++;
                } else if (sum > target) {
                    end--;
                }
            }
        }
        return ret;
    }
};
