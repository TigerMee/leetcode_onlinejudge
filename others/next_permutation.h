
#include "common.h"

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() <= 1) {
            return;
        }

        for (int i = num.size() - 1; i > 0; i--) {
            if (num[i-1] < num[i]) {
                // 1.将[i, num.size()-1]排序
                vector<int>::iterator it = num.begin();
                it += i;  // the item next to (i-1)
                sort(it, num.end());

                // 2.从i开始，找到第一个比(i-1)大的，并交换
                for (; it != num.end(); ++it) {
                    if (*it > num[i-1]) {
                        int tmp = num[i-1];
                        num[i-1] = *it;
                        *it = tmp;
                        break;
                    }
                }
                return;
            }
        }

        sort(num.begin(), num.end());
    }
};
