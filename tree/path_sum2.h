
#include "common.h"

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return vector<vector<int> >();
        }

        vector<vector<int> > res;

        if (root->left != NULL) {
            vector<vector<int> > lvv = pathSum(root->left, sum - root->val);
            for (int i = 0; i < lvv.size(); i++) {
                vector<int> v(1, root->val);
                for (int j = 0; j < lvv[i].size(); j++) {
                    v.push_back(lvv[i][j]);
                }
                res.push_back(v);
            }
        }
        if (root->right != NULL) {
            vector<vector<int> > rvv = pathSum(root->right, sum - root->val);
            for (int i = 0; i < rvv.size(); i++) {
                vector<int> v(1, root->val);
                for (int j = 0; j < rvv[i].size(); j++) {
                    v.push_back(rvv[i][j]);
                }
                res.push_back(v);
            }
        }

        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                vector<int> v(1, root->val);
                res.push_back(v);
            }
        }

        return res;
    }
};
