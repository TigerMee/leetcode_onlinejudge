
#include "common.h"

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return false;
        }

        if (root->left != NULL && hasPathSum(root->left, sum - root->val)) {
            return true;
        } else if (root->right != NULL && hasPathSum(root->right, sum - root->val)) {
            return true;
        }

        return root->left == NULL
                && root->right == NULL
                && (root->val) == sum;
    }
};
