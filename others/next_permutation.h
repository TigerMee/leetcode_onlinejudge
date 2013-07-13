
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
                // 1.��[i, num.size()-1]����
                vector<int>::iterator it = num.begin();
                it += i;  // the item next to (i-1)
                sort(it, num.end());

                // 2.��i��ʼ���ҵ���һ����(i-1)��ģ�������
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
