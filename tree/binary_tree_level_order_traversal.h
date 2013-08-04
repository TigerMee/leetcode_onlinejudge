
#include "common.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if (root == NULL) {
            return res;
        }

        std::queue<TreeNode*> q;
        vector<int> v;

        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            TreeNode *pn = q.front();
            q.pop();

            if (pn == NULL) {
                if (!v.empty()) {
                    res.push_back(v);
                    v.clear();
                }
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                v.push_back(pn->val);
                if (pn->left != NULL) {
                    q.push(pn->left);
                }
                if (pn->right != NULL) {
                    q.push(pn->right);
                }
            }
        }
        if (!v.empty()) {
            res.push_back(v);
        }
        return res;
    }
};
