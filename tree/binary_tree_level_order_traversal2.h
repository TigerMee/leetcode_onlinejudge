
#include "common.h"

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
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

            if (pn == NULL) {   // end of current level
                if (!v.empty()) {
                    res.insert(res.begin(), v);
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
            res.insert(res.begin(), v);
        }
        return res;
    }
};
