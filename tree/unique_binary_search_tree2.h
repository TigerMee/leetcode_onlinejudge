
#include "common.h"

class Solution {
public:
    typedef vector<TreeNode *> V;

    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generate(1, n);
    }

    V generate(int begin, int end) {
        V v;

        if (begin <= 0 || end < begin) {    // ¿ÕÊ÷
            v.push_back(NULL);
        }

        for (int i = begin; i <= end; i++) {
            V left = generate(begin, i-1);
            V right = generate(i+1, end);

            for (V::iterator lit = left.begin(); lit != left.end(); ++lit) {
                for (V::iterator rit = right.begin(); rit != right.end(); ++rit) {
                    TreeNode *t = new TreeNode(i);
                    t->left = *lit;
                    t->right = *rit;
                    v.push_back(t);
                }
            }
        }

        return v;
    }
};
